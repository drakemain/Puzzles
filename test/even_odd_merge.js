var chai = require('chai');
var assert = chai.assert;

var List = require('./../src/linked_list').List;
var evenOddArrays = require('./../src/even_odd_merge');

describe("Even Odd Merge", function() {
  it("should arrange nodes to start with even and end with odd indexes", function() {
    var thisList = List.fromArray([0, 1, 2, 3, 4]),
        expectedList = List.fromArray([0, 2, 4, 1, 3]);

    var thisList1 = List.fromArray(['a', 'b', 'c', 'd', 'e']),
        expectedList1 = List.fromArray(['a', 'c', 'e', 'b', 'd']);

    evenOddArrays(thisList);
    evenOddArrays(thisList1);

    console.log(thisList.toString());

    assert(thisList.equals(expectedList), 'numeric fail');
    assert(thisList1.equals(expectedList1), 'char fail');
  });
});