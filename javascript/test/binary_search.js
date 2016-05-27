var chai = require('chai');
var assert = chai.assert;

var binarySearch = require('./../src/binary_search');

describe('Binary Array Search', function() {
  var arr = [1, 2, 5, 6, 7, 8, 13, 15, 18, 19, 23, 30, 31];
  var valuesThatExist = buildValExistsArray(arr);

  it('should locate the correct value if it exists', function() {
    for (var i = valuesThatExist.length - 2; i > 0; i--) {
      console.log(valuesThatExist[i], i);
      assert.equal(valuesThatExist[i], binarySearch.array(arr, i), i);
    }
  });

  it('should return false for out of bounds cases', function() {
    assert.equal(valuesThatExist[0], false);
    assert.equal(valuesThatExist[32], false);
  })
});

function buildValExistsArray(arr) {
  var returnArr = new Array(arr[arr.length + 1]);
  var index = arr.length - 1;

  for (var i = arr[arr.length - 1] + 1; i >= 0; i--) {
    if (arr[index] === i) {
      returnArr[i] = true;
      index--;
    } else {
      returnArr[i] = false;
    }
  }

  return returnArr;
}