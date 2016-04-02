var chai = require('chai');
var assert = chai.assert;

var enumeratePrimes = require('./../src/enumerate_primes');

describe('Enumerate Primes', function() {
  it('should have all primes preceeding given integer', function() {
    assert.deepEqual(enumeratePrimes(18), [2, 3, 5, 7, 11, 13, 17]);
  });
});