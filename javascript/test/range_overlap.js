var chai = require('chai');
var assert = chai.assert;

var doesOverlap = require('./../src/range_overlap.js');

describe("Range Overlap", function() {
  it("should return true if ranges overlap", function() {
    assert(doesOverlap(1, 5, 4, 9), "fail");
    assert(doesOverlap(1, 3, 2, 4), "fail");
    assert(doesOverlap(2, 4, 1, 3), "fail");
    assert(doesOverlap(1, 4, 2, 3), "fail");
    assert(doesOverlap(2, 3, 1, 4), "fail");
  });

  it("should return false if there is no overlap", function() {
    assert(!doesOverlap(0, 5, 6, 11), "fail");
    assert(!doesOverlap(1, 2, 3, 4), "fail");
    assert(!doesOverlap(3, 4, 1, 2), "fail");
  });
});