/*
 * @version: 1.0.0
 * @Author: BruceCui
 * @Date: 2024-10-09 16:25:15
 * @LastEditors: BruceCui
 * @LastEditTime: 2024-10-14 12:35:36
 */
//
// Created by fss on 23-5-27.
//

#include <glog/logging.h>
#include <gtest/gtest.h>

#include <iostream>
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    google::InitGoogleLogging("Kuiper");
    FLAGS_log_dir = "../../course2/log";
    FLAGS_alsologtostderr = true;

    LOG(INFO) << "Start test...\n";
    return RUN_ALL_TESTS();
}