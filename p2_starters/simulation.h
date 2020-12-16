/*
 * This is VE280 Project 2, SU2020.
 * Written by Ziqiao Ma and Zhuoer Zhu.
 * Latest Update: 5/29/2020.
 * All rights reserved.
 */

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>

#include "server_type.h"

void wrong_argument(int argc);
// EFFECTS: warning wrong program argument

void open_file(ifstream* iFile, const string& address);
// MODIFIES: iFile
// EFFECTS: open a file

void initialize_user(ifstream* iFile, Server_t& server);
// MODIFIES: sever
// EFFECTS: generate user in the server

void initialize_user_info(ifstream* iFile, Server_t& server);
// MODIFIES: sever
// EFFECTS: generate user info in the server

void initialize_user_post(ifstream* iFile, Server_t& server);
// MODIFIES: sever
// EFFECTS: generate user post in the server

void trending(Tag_t* all_tags, unsigned int tag_num, unsigned int n);
// EFFECTS: print the trending

void follow(User_t* user1, User_t* user2);
// MODIFIES: *user1 *user2
// EFFECTS: user1 follow user2

void unfollow(User_t* user1, User_t* user2);
// MODIFIES: *user1 *user2
// EFFECTS: user1 unfollow user2

void like(User_t* user1, User_t* user2, unsigned int post_id);
// MODIFIES: *user1
// EFFECTS: user1 likes user2 post_id

void unlike(User_t* user1, User_t* user2, unsigned int post_id);
// MODIFIES: *user1
// EFFECTS: user1 unlikes user2 post_id

void comment(User_t* user1, User_t* user2, unsigned int post_id, const string& line);
// MODIFIES: *user1
// EFFECTS: user1 comment user2 post_id

void uncomment(User_t* user1, User_t* user2, unsigned int post_id, unsigned int comment_id);
// MODIFIES: *user1
// EFFECTS: user1 uncomment user2 post_id

void post(User_t* user, ifstream* iFile);
// MODIFIES: *user1
// EFFECTS: user1 post

void unpost(User_t* user, unsigned int post_id);
// MODIFIES: *user1
// EFFECTS: user1 unpost

void refresh(User_t* user);
// EFFECTS: print the post posted by the following of *user

void visit(User_t* user1, User_t* user2);
// EFFECTS: print the relationship and information of user2

void process_logfile(ifstream* iFile, Server_t& server, const string& line);
// MODIFIES: server
// EFFECTS: process user commend

/* Helper Functions */
int string2int (const string& str);
// EFFECT: return a int according to the given string

User_t* find_user (Server_t& server, const string& username);
// EFFECTS: return a pointer to the given user

void user_info_warning(unsigned int max, unsigned int n, const string& username, const string& type);
// EFFECTS: warning of wrong user info

void post_warning(unsigned int max, const string& title, const string& type);
// EFFECTS: warning of wrong user info

Post_t generate_post(ifstream* iFile, User_t* user);
// MODIFIES: iFile
// EFFECTS: read and generate a post

Comment_t generate_comment(ifstream* iFile, User_t* user);
// MODIFIES: iFile
// EFFECTS: read and generate a comment

Tag_t* find_tag(Server_t& server, const string& tagname);
// MODIFIES: server if tagname didn't exist
// EFFECTS: create the tag if it didn't exist. return a pointer to the tag(tagname).

bool compare(const Tag_t& tag1, const Tag_t& tag2);
// EFFECTS: compare function for sort

unsigned int delete_element(User_t** array, const string& username, unsigned int num);
// MODIFIES: *array
// EFFECTS: delete an element in *array

bool follow_user(User_t* user1, User_t* user2);
// EFFECTS: judge whether user1 followed user2

// Printing
void printUser(User_t& user, const string& relationship);
// EFFECTS: print user

void printPost(Post_t& post);
// EFFECTS: print post

void printTag(const Tag_t& tag, unsigned int rank);
// EFFECTS: print tag
#endif