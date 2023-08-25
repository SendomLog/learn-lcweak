//
//  CodecTest.m
//  learn-lcweakTests
//
//  Created by iMac on 2023/8/25.
//

#import <XCTest/XCTest.h>
#import "Codec.hpp"

@interface CodecTest : XCTestCase

@end

@implementation CodecTest

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testExample1 {
    string str = "1,2,3,null,null,4,5";
    Codec deserialize;
    TreeNode *root = deserialize.deserialize(str);
    string str2 = deserialize.serialize(root);
}

- (void)testExample2 {
    string str = "";
    Codec deserialize;
    TreeNode *root = deserialize.deserialize(str);
    string str2 = deserialize.serialize(root);
}

- (void)testExample3 {
    string str = "1,2";
    Codec deserialize;
    TreeNode *root = deserialize.deserialize(str);
    string str2 = deserialize.serialize(root);
}

- (void)testExample4 {
    string str = "1,2,3,null,null,4,5,6,7";
    Codec deserialize;
    TreeNode *root = deserialize.deserialize(str);
    string str2 = deserialize.serialize(root);
}


- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
