var chai = require('chai');
var assert = chai.assert;

var List = require('./../src/linked_list').List;
var evenOddArrays = require('./../src/even_odd_merge');

describe("Even Odd Merge", function() {
  it("should arrange nodes to start with even and end with odds", function() {
    var thisList = List.fromArray([0, 1, 2, 3, 4]),
        expectedList = List.fromArray([0, 2, 4, 1, 3]);

    evenOddArrays(thisList);

    console.log(thisList.toString());

    assert(thisList.equals(expectedList), 'fail');
  });
});