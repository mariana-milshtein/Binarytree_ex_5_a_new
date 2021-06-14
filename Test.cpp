#include "doctest.h"
#include "BinaryTree.hpp"

void init() {
    
}

TEST_CASE("Build BinaryTree") {
    BinaryTree<int> b;
    bool empty = true;
    for (auto i : b) {
        empty = false;
    }
    CHECK(empty);
}

TEST_CASE("Root") {
    BinaryTree<int> b;
    b.add_root(10);
    int n = 0;
    for (auto i : b) {
        CHECK(i == 10);
        n++;
    }
    CHECK(n==1);    
}
TEST_CASE("Change Root") {
    BinaryTree<int> b;
    b.add_root(10);
    b.add_root(5);
     int n = 0;
    for (auto i : b) {
        CHECK(i == 5);
        n++;
    }
    CHECK(n==1); 
}

TEST_CASE("Add left empty") {
    BinaryTree<int> b;
    CHECK_THROWS(b.add_left(2,1));
}

TEST_CASE("Add left not found") {
    BinaryTree<int> b;
    b.add_root(10);
    CHECK_THROWS(b.add_left(2,10));
}

TEST_CASE("Add left") {
    BinaryTree<int> b;
    b.add_root(10);
    b.add_left(10,15);
    int n = 0;
    auto i = b.begin();
    CHECK(*i == 15);
    i++;
    CHECK(*i == 10);
    i++;
    CHECK(i == nullptr); 
}

TEST_CASE("Add left") {
    BinaryTree<int> b;
    b.add_root(10);
    b.add_left(10,15);
    int n = 0;
    auto i = b.begin();
    CHECK(*i == 15);
    i++;
    CHECK(*i == 10);
    i++;
    CHECK(i == nullptr); 
}

TEST_CASE("Add left change") {
     BinaryTree<int> b;
    b.add_root(10);
    b.add_left(10,15);
    b.add_left(10,4);
    int n = 0;
    auto i = b.begin();
    CHECK(*i == 4);
    i++;
    CHECK(*i == 10);
    i++;
    CHECK(i == nullptr); 
}


TEST_CASE("Add right empty") {
    BinaryTree<int> b;
    CHECK_THROWS(b.add_right(2,1));
}

TEST_CASE("Add right not found") {
    BinaryTree<int> b;
    b.add_root(10);
    CHECK_THROWS(b.add_right(2,10));
}

TEST_CASE("Add right") {
    BinaryTree<int> b;
    b.add_root(10);
    b.add_right(10,15);
    int n = 0;
    auto i = b.begin();
    CHECK(*i == 10);
    i++;
    CHECK(*i == 15);
    i++;
    CHECK(i == nullptr); 
}


TEST_CASE("Add right change") {
     BinaryTree<int> b;
    b.add_root(10);
    b.add_right(10,15);
    b.add_right(10,4);
    int n = 0;
    auto i = b.begin();
    CHECK(*i == 10);
    i++;
    CHECK(*i == 4);
    i++;
    CHECK(i == nullptr); 
}

TEST_CASE("Add left and right") {
    BinaryTree<int> b;
    b.add_root(10);
    b.add_right(10,15);
    b.add_left(10,4);
    int n = 0;
    auto i = b.begin();
    CHECK(*i == 4);
    i++;
    CHECK(*i == 10);
    i++;
    CHECK(*i == 15);
    i++;
    CHECK(i == nullptr);   
}


TEST_CASE("Add left and right 2") {
    BinaryTree<int> b;
    b.add_root(10);
    b.add_right(10,15);
    b.add_left(15,4);
    int n = 0;
    auto i = b.begin();
    CHECK(*i == 10);
    i++;
    CHECK(*i == 4);
    i++;
    CHECK(*i == 15);
    i++;
    CHECK(i == nullptr);   
}

TEST_CASE("Iterators 1") {
    BinaryTree<int> b;
    b.add_root(10);
    b.add_right(10,20);
    b.add_left(10,5);
    b.add_left(5,2);
    b.add_right(5,7);
    b.add_right(7,9);
    b.add_right(20,30);
    b.add_left(30,25);
    auto i = b.begin_inorder();
    CHECK(*i == 2);
    ++i;
    CHECK(*i == 5);
    ++i;
    CHECK(*i == 7);
    ++i;
    CHECK(*i == 9);
    ++i;
    CHECK(*i == 10);
    i++;
    CHECK(*i == 20);
    ++i;
    CHECK(*i == 25);
    ++i;
    CHECK(*i == 30);
    ++i;
    CHECK(i == nullptr);
}

TEST_CASE("Iterators 2") {
    BinaryTree<int> b;
    b.add_root(10);
    b.add_right(10,20);
    b.add_left(10,5);
    b.add_left(5,2);
    b.add_right(5,7);
    b.add_right(7,9);
    b.add_right(20,30);
    b.add_left(30,25);
    auto i = b.begin_preorder();
    CHECK(*i == 10);
    ++i;
    CHECK(*i == 5);
    ++i;
    CHECK(*i == 2);
    ++i;
    CHECK(*i == 7);
    ++i;
    CHECK(*i == 9);
    ++i;
    CHECK(*i == 20);
    ++i;
    CHECK(*i == 30);
    ++i;
    CHECK(*i == 25);
    ++i;
    CHECK(i == nullptr);
}

