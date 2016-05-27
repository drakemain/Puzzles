var chai = require('chai');
var assert = chai.assert;

var binSearchArray = require('./../src/binary_search_array');

describe('Binary Array Search', function() {
  it('should locate the correct value if it exists', function() {
    var arr = [1, 2, 5, 6, 7, 8, 13, 15, 18, 19, 23, 30, 31];

    var valuesThatExist = buildValExistsArray(arr);

    for (var i = valuesThatExist.length - 1; i >= 0; i--) {
      console.log(valuesThatExist[i], i);
      assert.equal(valuesThatExist[i], binSearchArray(arr, i), i);
    }
  });
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