var chai = require('chai');
var assert = chai.assert;

var enumeratePrimes = require('./../src/enumerate_primes');

describe('Enumerate Primes: ', function() {
  it('should have all primes preceeding given integer', function() {
    var input = 18;
    var expected = [2, 3, 5, 7, 11, 13, 17];
    var result = enumeratePrimes(input);

    assert.deepEqual(result, expected);
  });
});