//
// Created by zhuxingyu88 on 2020/6/2.
//

#include <iostream>
#include <string>

#include "server_type.h"
#include "simulation.h"


int main(int argc, char *argv[]){
    ifstream iFile;
    Server_t server;
    try{
        wrong_argument(argc);
        open_file(&iFile, argv[1]);
        initialize_user(&iFile, server);
        iFile.close();
        initialize_user_info(&iFile, server);
        initialize_user_post(&iFile, server);
        open_file(&iFile, argv[2]);
    } catch (Exception_t &exception){
        if (iFile.is_open()) iFile.close();
        cout << exception.error_info;
        return 0;
    }
    //printPost(server.all_users[0].posts[0]);
    string line;
    while (getline(iFile, line)) {
        try {
            process_logfile(&iFile, server, line);
        } catch (Exception_t &exception) {
            cout << exception.error_info;
        }
    }
    if (iFile.is_open()) iFile.close();
    //printUser(server.all_users[0], "aaa");
    return 0;
}
