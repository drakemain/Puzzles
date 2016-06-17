var chai = require('chai');
var assert = chai.assert;

var lookAndSay = require('./../src/look_and_say');

describe("Look and Say String Method", function() {
  it("Should construct the correct number in the sequence", function() {
    var expected7 = "13112221";
    var expected8 = "1113213211";

    assert.equal(lookAndSay.asString(7), expected7);
    assert.equal(lookAndSay.asString(8), expected8);
  });

  it("should handle input of 0", function() {
    assert.equal(lookAndSay.asString(0), "0");
  });

  it("should handle input of 1", function() {
    assert.equal(lookAndSay.asString(1), "1");
  });
});

describe("Look and Say Numeric Method", function() {
  it("Should construct the correct number in the sequence", function() {
    assert.equal(lookAndSay.noString(7), 13112221);
    assert.equal(lookAndSay.noString(8), 1113213211);
  });

  it("should handle input of 0", function() {
    assert.equal(lookAndSay.asString(0), "0");
  });

  it("should handle input of 1", function() {
    assert.equal(lookAndSay.asString(1), "1");
  });
});