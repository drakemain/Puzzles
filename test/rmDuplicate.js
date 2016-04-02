var chai = require('chai');
var assert = chai.assert;

rmduplicates = require('./../src/rmDuplicate');

var arr = [1, 2, 3, 5, 5, 7, 9, 9, 11, 11, 11, 13];
var expected = [1, 2, 3, 5, 7, 9, 11, 13, 0, 0, 0, 0];

describe('Array', function(){
  it('Should equal expected', function() {
    rmduplicates(arr);

    assert.equal(arr, expected);
  });
});