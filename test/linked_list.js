var chai = require('chai');
var assert = chai.assert;

var List = require('./../src/linked_list').List;
var removeSecondNode = require('./../src/linked_list').removeSecondNode;
var removeNode = require('./../src/linked_list').removeNode;

describe('Linked List', function() {
  it('can be built from an array', function() {
    var list = List.fromArray([0, 1, 2, 3, 4]);

    var list2 =
          new List(0,
                   new List(1,
                            new List(2,
                                     new List(3,
                                              new List(4, null)))));

    assert(list.equals(list2));
  });

  it('can append an array', function() {
    var list = new List(0, null);
    list.appendArray([1, 2, 3, 4]);

    var list2 = new List.fromArray([0, 1, 2, 3, 4]);

    assert(list.equals(list2));
  });

  it('should check for equality', function() {
    var list =
          new List(0,
                   new List(1,
                            new List(2,
                                     new List(3,
                                              new List(4, null)))));

    var list2 =
          new List(0,
                   new List(1,
                            new List(2,
                                     new List(3,
                                              new List(4, null)))));
    assert(list.equals(list2));
  });

  it('should not consider two arrays with equal prefix to be equal', function() {
    var list = List.fromArray([0, 1, 2, 3, 4]);
    var list2 = List.fromArray([0, 1, 2]);

    assert(!list.equals(list2));
  });

  it('should convert to string', function() {
    var list = List.fromArray([0, 1, 2, 3, 4]);

    assert.equal(list.toString(), "0 → 1 → 2 → 3 → 4");
  });

  it('should get the length of the list', function() {
    var list = List.fromArray([0, 1, 2, 3, 4, 5, 6, 7]);

    assert.equal(list.length(), 8);
  });

  it('should remove the second node from this list', function() {
    var list = List.fromArray([0, 1, 2, 3, 4, 5]);

    list.removeNode(1);

    assert(list.equals(List.fromArray([0, 2, 3, 4, 5])), 'fail');
  });

  it('should remove the last node from this list', function() {
    var list = List.fromArray([0, 1, 2, 3, 4, 5]);

    list.removeNode(5);

    assert(list.equals(List.fromArray([0, 1, 2, 3, 4])), 'fail');
  });

  it('should end with same list if node to remove is greater than list length', function() {
    var list = List.fromArray([0, 1, 2, 3, 4, 5]);

    list.removeNode(6);

    assert(list.equals(List.fromArray([0, 1, 2, 3, 4, 5])), 'fail');
  })
});
