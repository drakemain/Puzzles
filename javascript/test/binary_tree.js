var chai = require("chai");
var assert = chai.assert;

var BinaryTree = require("./../src/binary_tree").BinaryTree;

describe("Binary Tree", function() {
  it("should determine if a value exists in the tree", function() {
    var tree = new BinaryTree(10, new BinaryTree(5), new BinaryTree(15));

    assert(tree.contains(10), "contains 10");
    assert(tree.contains(5), "contains 5");
    assert(tree.contains(15), "contains 15");

    assert(!tree.contains(1), "does not contain 1");
    assert(!tree.contains(9), "does not contain 9");
    assert(!tree.contains(11), "does not contain 11");
    assert(!tree.contains(16), "does not contain 16");

  });
});