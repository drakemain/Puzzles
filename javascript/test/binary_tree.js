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
});