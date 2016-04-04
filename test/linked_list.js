var chai = require('chai');
var assert = chai.assert;

var List = require('./../src/linked_list');

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

  it('should convert to string', function() {
    var list = List.fromArray([0, 1, 2, 3, 4]);

    assert.equal(list.toString(), "0 → 1 → 2 → 3 → 4");
  });
});
