/*
 * This is VE280 Project 2, SU2020.
 * Written by Ziqiao Ma and Zhuoer Zhu.
 * Latest Update: 5/29/2020.
 * All rights reserved.
 */

#include "simulation.h"


void wrong_argument(int argc){
    // warning wrong program argument
    if(argc < 3) {
        ostringstream oStream;
        oStream << "Error: Wrong number of arguments!" << endl;
        oStream << "Usage: ./p2 <username> <logfile>" << endl;
        throw Exception_t(INVALID_ARGUMENT, oStream.str());
    }
}

void open_file(ifstream* iFile, const string& address) {
    // open a file
    iFile->open(address);
    if (!*iFile){
        ostringstream oStream;
        oStream << "Error: Cannot open file " << address << "!" << endl;
        throw Exception_t(FILE_MISSING, oStream.str());
    }
}

void initialize_user(ifstream* iFile, Server_t& server) {
    // generate user in the server
    getline(*iFile, server.user_dic);
    unsigned int i = 0;
    while(getline(*iFile, server.all_users[i].username)) {
        ++i;
        if (i > MAX_USERS) iFile->get();
        if (i >= MAX_USERS && *iFile) {
            ostringstream oStream;
            oStream << "Error: Too many users!" << endl;
            oStream << "Maximal number of users is " << MAX_USERS << "." << endl;
            throw Exception_t(CAPACITY_OVERFLOW, oStream.str());
        }
    }
    server.num_users = i;
}

void initialize_user_info(ifstream* iFile, Server_t& server) {
    // generate user info in the server
    string line;
    for (unsigned int i = 0; i < server.num_users; ++i) {
        open_file(iFile, server.user_dic + '/' + server.all_users[i].username + "/user_info");
        getline(*iFile, line);
        server.all_users[i].num_posts = string2int(line);
        user_info_warning(MAX_POSTS, server.all_users[i].num_posts, server.all_users[i].username, "posts");

        getline(*iFile, line);
        server.all_users[i].num_following = string2int(line);
        user_info_warning(MAX_FOLLOWING, server.all_users[i].num_following, server.all_users[i].username, "followings");
        for (unsigned int j = 0; j < server.all_users[i].num_following; ++j) {
            getline(*iFile, line);
            server.all_users[i].following[j] = find_user(server,line);
        }

        getline(*iFile, line);
        server.all_users[i].num_followers = string2int(line);
        user_info_warning(MAX_FOLLOWERS, server.all_users[i].num_followers, server.all_users[i].username, "followers");
        for (unsigned int k = 0; k < server.all_users[i].num_followers; ++k) {
            getline(*iFile, line);
            server.all_users[i].follower[k] = find_user(server, line);
        }
        iFile->close();
    }
}

void initialize_user_post(ifstream* iFile, Server_t& server) {
    // generate user post in the server
    string line;
    for (unsigned int i = 0; i < server.num_users; ++i) {
        for (unsigned int j = 0; j < server.all_users[i].num_posts; ++j) {
            open_file(iFile, server.user_dic + '/' + server.all_users[i].username + "/posts/" + to_string(j + 1));
            server.all_users[i].posts[j] = generate_post(iFile, &server.all_users[i]);

            getline(*iFile, line);
            server.all_users[i].posts[j].num_likes = string2int(line);
            if (server.all_users[i].posts[j].num_likes >= MAX_LIKES)
                post_warning(MAX_LIKES, server.all_users[i].posts[j].title, "likes");
            for (unsigned int k = 0; k < server.all_users[i].posts[j].num_likes; ++k) {
                getline(*iFile, line);
                server.all_users[i].posts[j].like_users[k] = find_user(server, line);
            }

            getline(*iFile, line);
            server.all_users[i].posts[j].num_comments = string2int(line);
            if (server.all_users[i].posts[j].num_comments >= MAX_COMMENTS)
                post_warning(MAX_COMMENTS, server.all_users[i].posts[j].title, "comments");
            for (unsigned int l = 0; l < server.all_users[i].posts[j].num_comments; ++l) {
                getline(*iFile, line);
                server.all_users[i].posts[j].comments[l] = generate_comment(iFile, find_user(server, line));
            }
            iFile->close();

            for (unsigned int m = 0; m < server.all_users[i].posts[j].num_tags; ++m) {
                find_tag(server, server.all_users[i].posts[j].tags[m])->tag_score += (5 + 3 * server.all_users[i].posts[j].num_comments + server.all_users[i].posts[j].num_likes);
            }
        }
    }

}

void trending(Tag_t* all_tags, unsigned int num_tag, unsigned int n) {
    // trending commend
    cout << ">> trending" << endl;
    sort(all_tags, all_tags + num_tag, compare);
    if (num_tag < n) n = num_tag;
    for (unsigned int i = 0; i < n && (all_tags + i)->tag_score > 0; ++i) {
        printTag(*(all_tags + i), i + 1);
    }
}

void follow(User_t* user1, User_t* user2) {
    // follow commend: user1 follow user2
    cout << ">> follow" << endl;
    user1->following[user1->num_following++] = user2;
    user2->follower[user2->num_followers++] = user1;
}

void unfollow(User_t* user1, User_t* user2) {
    // unfollow commend: user1 unfollow user2
    cout << ">> unfollow" << endl;
    user1->num_following = delete_element(user1->following, user2->username, user1->num_following);
    user2->num_followers = delete_element(user2->follower, user1->username, user2->num_followers);
}

void like(User_t* user1, User_t* user2, unsigned int post_id) {
    // user1 likes user2 post_id
    cout << ">> like" << endl;
    if (user2->num_posts < post_id) {
        ostringstream oStream;
        oStream << "Error: " + user1->username + " cannot like post #" << post_id << " of " + user2->username + "!" << endl;
        oStream << user2->username + " does not have post #" << post_id << "." << endl;
        throw Exception_t(INVALID_LOG, oStream.str());
    }
    for (unsigned int i = 0; i < user2->posts[post_id - 1].num_likes; ++i) {
        if (user2->posts[post_id - 1].like_users[i]->username == user1->username){
            ostringstream oStream;
            oStream << "Error: " + user1->username + " cannot like post #" << post_id << " of " + user2->username + "!" << endl;
            oStream << user1->username + " has already liked post #" << post_id << " of " + user2->username + "."  << endl;
            throw Exception_t(INVALID_LOG, oStream.str());
        }
    }
    user2->posts[post_id-1].like_users[user2->posts[post_id - 1].num_likes++] = user1;
}

void unlike(User_t* user1, User_t* user2, unsigned int post_id) {
    // user1 unlikes user2 post_id
    cout << ">> unlike" << endl;
    if (user2->num_posts < post_id) {
        ostringstream oStream;
        oStream << "Error: " + user1->username + " cannot unlike post #" << post_id << " of " + user2->username + "!" << endl;
        oStream << user2->username + " does not have post #" << post_id << "." << endl;
        throw Exception_t(INVALID_LOG, oStream.str());
    }
    unsigned int n = delete_element(user2->posts[post_id - 1].like_users, user1->username, user2->posts[post_id - 1].num_likes);
    if (user2->posts[post_id - 1].num_likes == n) {
        ostringstream oStream;
        oStream << "Error: " + user1->username + " cannot unlike post #" << post_id << " of " + user2->username + "!" << endl;
        oStream << user1->username + " has not liked post #" << post_id << " of " + user2->username + "."  << endl;
        throw Exception_t(INVALID_LOG, oStream.str());
    } else user2->posts[post_id - 1].num_likes = n;
}

void comment(User_t* user1, User_t* user2, unsigned int post_id, const string& line) {
    // user1 comment user2 post_id
    cout << ">> comment" << endl;
    if (user2->num_posts < post_id) {
        ostringstream oStream;
        oStream << "Error: " + user1->username + " cannot comment post #" << post_id << " of " + user2->username + "!" << endl;
        oStream << user2->username + " does not have post #" << post_id << "." << endl;
        throw Exception_t(INVALID_LOG, oStream.str());
    }
    user2->posts[post_id - 1].comments[user2->posts[post_id - 1].num_comments].text = line;
    user2->posts[post_id - 1].comments[user2->posts[post_id - 1].num_comments++].user = user1;
}

void uncomment(User_t* user1, User_t* user2, unsigned int post_id, unsigned int comment_id) {
    // user1 uncomment user2 post_id
    cout << ">> uncomment" << endl;
    if (user2->num_posts < post_id) {
        ostringstream oStream;
        oStream << "Error: " + user1->username + " cannot uncomment comment #" << comment_id << " of post #" << post_id << " posted by " + user2->username + "!" << endl;
        oStream << user2->username + " does not have post #" << post_id << "." << endl;
        throw Exception_t(INVALID_LOG, oStream.str());
    }
    if (user2->posts[post_id - 1].num_comments < comment_id) {
        ostringstream oStream;
        oStream << "Error: " + user1->username + " cannot uncomment comment #" << comment_id << " of post #" << post_id << " posted by " + user2->username + "!" << endl;
        oStream << "Post #" << post_id << " does not have comment #" << comment_id << "." << endl;
        throw Exception_t(INVALID_LOG, oStream.str());
    }
    if (user2->posts[post_id - 1].comments[comment_id - 1].user != user1) {
        ostringstream oStream;
        oStream << "Error: " + user1->username + " cannot uncomment comment #" << comment_id << " of post #" << post_id << " posted by " + user2->username + "!" << endl;
        oStream << user1->username + " is not the owner of comment #" << comment_id << "." << endl;
        throw Exception_t(INVALID_LOG, oStream.str());
    }
    for (unsigned int i = comment_id; i < user2->posts[post_id - 1].num_comments; ++i) {
        user2->posts[post_id - 1].comments[i - 1] = user2->posts[post_id - 1].comments[i];
    }
    user2->posts[post_id - 1].comments[user2->posts[post_id - 1].num_comments--] = Comment_t();
}

void post(User_t* user, ifstream* iFile) {
    // read posts and post
    cout << ">> post" << endl;
    user->posts[user->num_posts++] = generate_post(iFile, user);
}

void unpost(User_t* user, unsigned int post_id) {
    // delete a post
    for (unsigned int i = post_id; i < user->num_posts; ++i) {
        user->posts[i-1] = user->posts[i];
    }
    user->posts[user->num_posts--] = Post_t();
}

void refresh(User_t* user) {
    // print the post posted by the following of *user
    cout << ">> refresh" << endl;
    for (unsigned int i = 0; i < user->num_posts; ++i) {
        printPost(user->posts[i]);
    }
    for (unsigned int j = 0; j < user->num_following; ++j) {
        for (unsigned int k = 0; k < user->following[j]->num_posts; ++k) {
            printPost(user->following[j]->posts[k]);
        }
    }
}

void visit(User_t* user1, User_t* user2) {
    // print the relationship and information of user2
    cout << ">> visit" << endl;
    string relationship;
    if (user1 == user2) relationship = "";
    else if (follow_user(user1, user2)) {
        if (follow_user(user2, user1)) relationship = "friend";
        else relationship = "following";
    }
    else relationship = "stranger";
    printUser(*user2, relationship);
}

void process_logfile(ifstream* iFile, Server_t& server, const string& line) {
    // processing stage
    istringstream iStream;
    string user1;
    iStream.str(line);
    iStream >> user1;
    if (user1 == "trending") {
        int num;
        iStream >> num;
        iStream.clear();
        trending(server.all_tags, server.num_tags, num);
    } else {
        string request;
        iStream >> request;
        if (request == "follow") {
            string user2;
            iStream >> user2;
            iStream.clear();
            follow(find_user(server, user1), find_user(server, user2));
        } else if (request == "unfollow") {
            string user2;
            iStream >> user2;
            iStream.clear();
            unfollow(find_user(server, user1), find_user(server, user2));
        } else if (request == "like") {
            string user2;
            unsigned int num;
            iStream >> user2 >> num;
            iStream.clear();
            like(find_user(server, user1), find_user(server, user2), num);
            for (unsigned int i = 0; i < find_user(server, user2)->posts[num - 1].num_tags; ++i) {
                find_tag(server, find_user(server, user2)->posts[num - 1].tags[i])->tag_score += 1;
            }
        } else if (request == "unlike") {
            string user2;
            unsigned int num;
            iStream >> user2 >> num;
            iStream.clear();
            unlike(find_user(server, user1), find_user(server, user2), num);
            for (unsigned int i = 0; i < find_user(server, user2)->posts[num - 1].num_tags; ++i) {
                find_tag(server, find_user(server, user2)->posts[num - 1].tags[i])->tag_score -= 1;
            }
        } else if (request == "comment") {
            string user2;
            unsigned int num;
            iStream >> user2 >> num;
            iStream.clear();
            string text;
            getline(*iFile, text);
            comment(find_user(server, user1), find_user(server, user2), num, text);
            for (unsigned int i = 0; i < find_user(server, user2)->posts[num - 1].num_tags; ++i) {
                find_tag(server, find_user(server, user2)->posts[num - 1].tags[i])->tag_score += 3;
            }
        } else if (request == "uncomment") {
            string user2;
            unsigned int post_id, comment_id;
            iStream >> user2 >> post_id >> comment_id;
            iStream.clear();
            uncomment(find_user(server, user1), find_user(server, user2), post_id, comment_id);
            for (unsigned int i = 0; i < find_user(server, user2)->posts[post_id - 1].num_tags; ++i) {
                find_tag(server, find_user(server, user2)->posts[post_id - 1].tags[i])->tag_score -= 3;
            }
        } else if (request == "post") {
            iStream.clear();
            post(find_user(server, user1), iFile);
            for (unsigned int i = 0; i < find_user(server, user1)->posts[find_user(server, user1)->num_posts - 1].num_tags; ++i) {
                find_tag(server, find_user(server, user1)->posts[find_user(server, user1)->num_posts - 1].tags[i])->tag_score += 5;
            }
        } else if (request == "delete") {
            unsigned int post_id;
            iStream >> post_id;
            iStream.clear();
            cout << ">> delete" << endl;
            if (find_user(server, user1)->num_posts < post_id) {
                ostringstream oStream;
                oStream << "Error: " + find_user(server, user1)->username + " cannot delete post #" << post_id << "!" << endl;
                oStream << find_user(server, user1)->username + " does not have post #" << post_id << "." << endl;
                throw Exception_t(INVALID_LOG, oStream.str());
            }
            Post_t* post = &find_user(server, user1)->posts[post_id - 1];
            for (unsigned int i = 0; i < post->num_tags; ++i) {
                find_tag(server, post->tags[i])->tag_score -= (5 + 3 * post->num_comments + post->num_likes);
            }
            unpost(find_user(server, user1), post_id);
        } else if (request == "refresh") {
            iStream.clear();
	    refresh(find_user(server, user1));
        } else if (request == "visit") {
            string user2;
            iStream >> user2;
            iStream.clear();
            visit(find_user(server, user1), find_user(server, user2));
        }
    }
}

/* Helper Functions */
User_t* find_user(Server_t& server, const string& username) {
    // return a pointer to the given user
    for (unsigned int i = 0; i < server.num_users; ++i) {
        if (server.all_users[i].username == username) return &server.all_users[i];
    }
    return nullptr;
}

int string2int(const string& str) {
    // string int convert
    int n;
    istringstream iStream;
    iStream.str(str);
    iStream >> n;
    return n;
}

void user_info_warning(unsigned int max, unsigned int n, const string& username, const string& type) {
    // warning detection
    if(n > max) {
        ostringstream oStream;
        oStream << "Error: Too many " + type + " for user " << username << '!' << endl;
        oStream << "Maximal number of " + type + " is " << max << '.' << endl;
        throw Exception_t(CAPACITY_OVERFLOW, oStream.str());
    }
}

void post_warning(unsigned int max, const string& title, const string& type) {
    // warning detection
    ostringstream oStream;
    oStream << "Error: Too many " + type + " for post " << title << '!' << endl;
    oStream << "Maximal number of " + type + " is " << max << '.' << endl;
    throw Exception_t(CAPACITY_OVERFLOW, oStream.str());
}

Post_t generate_post(ifstream* iFile, User_t* user) {
    // read and generate a post
    string line;
    Post_t post;
    post.owner = user;
    post.num_tags = 0;
    post.num_comments = 0;
    post.num_likes = 0;
    getline(*iFile, post.title);
    while(getline(*iFile, line)) {
        if (line[0] == '#') {
            if (post.num_tags >= MAX_TAGS) post_warning(MAX_TAGS, post.title, "tags");
            post.tags[post.num_tags++] = line.substr(1, line.length() - 2);
        } else {
            post.text = line;
            return post;
        }
    }
    return post;
}

Comment_t generate_comment(ifstream* iFile, User_t* user) {
    // return a comment
    Comment_t comment;
    comment.user = user;
    getline(*iFile, comment.text);
    return comment;
}

Tag_t* find_tag (Server_t& server, const string& tagname) {
    // create the tag if it didn't exist. return a pointer to the tag(tagname).
    for (unsigned int i = 0; i < server.num_tags; ++i) {
        if (server.all_tags[i].tag_content == tagname) return &server.all_tags[i];
    }
    server.all_tags[server.num_tags].tag_content = tagname;
    server.all_tags[server.num_tags].tag_score = 0;
    return &server.all_tags[server.num_tags++];
}

bool compare(const Tag_t& tag1, const Tag_t& tag2) {
    // compare function for sort
    if ( tag1.tag_score >  tag2.tag_score ) return true;
    else if ( tag1.tag_score <  tag2.tag_score ) return false;
    else if ( tag1.tag_score == tag2.tag_score ) return tag1.tag_content < tag2.tag_content;
    return true;
}

unsigned int delete_element(User_t** array, const string& username, unsigned int num) {
    // move every element after username forward
    unsigned int n_user = 0;
    for (unsigned int i = 0; i < num; ++i) {
        if (array[i]->username == username)
            continue;
        array[n_user++] = array[i];
    }
    return n_user;
}

bool follow_user(User_t* user1, User_t* user2) {
    // return true if user1 followed user 2
    for (unsigned int i = 0; i < user1->num_following; ++i) {
        if (user1->following[i] == user2) return true;
    }
    return false;
}

// Printing

void printUser(User_t& user, const string& relationship){
    // print user
    cout << user.username << endl;
    cout << relationship << endl;
    cout << "Followers: " << user.num_followers
         << "\nFollowing: " << user.num_following << endl;
}


void printPost(Post_t& post){
    // print post
    cout << post.owner->username << endl;
    cout << post.title << endl;
    cout << post.text << endl;
    cout << "Tags: ";
    for (unsigned int i = 0; i<post.num_tags; ++i){
        cout << post.tags[i] << " ";
    }
    cout << "\nLikes: " << post.num_likes << endl;
    if (post.num_comments > 0){
        cout << "Comments:" << endl;
        for(unsigned int i = 0; i<post.num_comments; ++i){
            cout << post.comments[i].user->username << ": "
                 << post.comments[i].text << endl;
        }
    }
    cout << "- - - - - - - - - - - - - - -" << endl;
}


void printTag(const Tag_t& tag, unsigned int rank){
    // print tag
    cout << rank << " " << tag.tag_content << ": " << tag.tag_score << endl;
}
