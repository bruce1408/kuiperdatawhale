/*
 * @Author: mikey.zhaopeng 
 * @Date: 2024-10-13 14:49:12 
 * @Last Modified by:   mikey.zhaopeng 
 * @Last Modified time: 2024-10-13 14:49:12 
 */

#include <gtest/gtest.h>
#include <glog/logging.h>

int main(int argc, char *argv[]) {
  
    testing::InitGoogleTest(&argc, argv);

    google::InitGoogleLogging("Kuiper");

    FLAGS_log_dir = "../../course1/log";

    FLAGS_alsologtostderr = true;

    LOG(INFO) << "Start test...\n";

    int ret = RUN_ALL_TESTS();

    google::ShutdownGoogleLogging();

    return ret;
}