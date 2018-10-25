var chai = require('chai');
var assert = chai.assert;

var reverseWordArray = require('./../src/reverse_word_array');

describe('Reverse Word Array', function() {
  it('Should reverse the order of the words.', function() {
    let input = ['p', 'e', 'r', 'f', 'e', 'c', 't', ' ', 'm', 'a', 'k', 'e', 's', ' ', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e'];
    let expectedResult = ['p', 'r', 'a', 'c', 't', 'i', 'c', 'e', ' ', 'm', 'a', 'k', 'e', 's', ' ', 'p', 'e', 'r', 'f', 'e', 'c', 't'];
    let result = reverseWordArray(input);
    assert.deepEqual(result, expectedResult);

    input = 'test a is this'.split('');
    expectedResult = 'this is a test'.split('');
    result = reverseWordArray(input);
    assert.deepEqual(input, expectedResult);

    input = 'hello world'.split('');
    expectedResult = 'world hello'.split('');
    result = reverseWordArray(input);
    assert.deepEqual(input, expectedResult);

    input = 'brevity is the soul of wit'.split('');
    expectedResult = 'wit of soul the is brevity'.split('');
    result = reverseWordArray(input);
    assert.deepEqual(result, expectedResult);
  });
});