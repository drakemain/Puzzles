var chai = require('chai');
var assert = chai.assert;

var rmduplicates = require('./../src/remove_duplicates');

describe('Array', function(){
  it('Should remove duplicates', function() {
    var arr = [1, 2, 3, 5, 5, 7, 9, 9, 11, 11, 11, 13];
    var expected = [1, 2, 3, 5, 7, 9, 11, 13, 0, 0, 0, 0];

    rmduplicates(arr);

    assert.deepEqual(arr, expected);
  });

  it('Should handle empty arrays', function() {
    var arr = [];
    var expected = [];

    rmduplicates(arr);

    assert.deepEqual(arr, expected);

  });
});