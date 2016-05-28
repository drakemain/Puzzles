var chai = require("chai");
var assert = chai.assert;

var BinaryTree = require("./../src/binary_tree").BinaryTree;

describe("Binary Tree", function() {
  it("should determine if a value exists in the tree", function() {
    var tree = new BinaryTree(10, new BinaryTree(5), new BinaryTree(15));

    assert(tree.contains(10), "didn't find 10");
    assert(tree.contains(5), "didn't find 5");
    assert(tree.contains(15), "didn't find 15");

    assert(!tree.contains(1), "found 1");
    assert(!tree.contains(9), "found 9");
    assert(!tree.contains(11), "found 11");
    assert(!tree.contains(16), "found 16");
  });

  it("should be able to insert values into the tree", function() {
    var tree = new BinaryTree(10, new BinaryTree(5), new BinaryTree(15));

    tree.insert(3);
    tree.insert(8);
    tree.insert(12);
    tree.insert(17);

    tree.insert(2);
    tree.insert(1);
    tree.insert(0);

    assert(tree.contains(3), "didn't find 3");
    assert(tree.contains(8), "didn't find 8");
    assert(tree.contains(12), "didn't find 12");
    assert(tree.contains(17), "didn't find 17");
    assert(tree.contains(2), "didn't find 2");
    assert(tree.contains(1), "didn't find 1");
    assert(tree.contains(0), "didn't find 0");

    assert(!tree.contains(-10), "found -10");
    assert(!tree.contains(16), "found 16");
    assert(!tree.contains(25), "found 25");
  });
});