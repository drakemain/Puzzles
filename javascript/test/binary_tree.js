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

  it("should create a path through the tree to a specified value", function() {
    var tree = new BinaryTree(10);

    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(8);
    tree.insert(12);
    tree.insert(17);
    tree.insert(2);
    tree.insert(1);
    tree.insert(0);
    tree.insert(20);
    tree.insert(19);
    tree.insert(16);
    tree.insert(21);

    assert.equal(tree.pathTo(17), "10 (R)→ 15 (R)→ 17", "17");
    assert.equal(tree.pathTo(19), "10 (R)→ 15 (R)→ 17 (R)→ 20 (L)→ 19", "19");
    assert.equal(tree.pathTo(16), "10 (R)→ 15 (R)→ 17 (L)→ 16", "16");
    assert.equal(tree.pathTo(14), "10 (R)→ 15 (L)→ 12 (R)→ ∅", "14");
  });
});