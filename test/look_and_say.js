var chai = require('chai');
var assert = chai.assert;

var lookAndSay = require('./../src/look_and_say');

describe("Look and say", function() {
  it("should consctruct subsequent numbers properly", function() {
    var expected7 = "13112221";
    var expected8 = "1113213211";

    assert.equal(lookAndSay(7), expected7);
    assert.equal(lookAndSay(8), expected8);
  });

  it("should handle input of 0", function() {
    assert.equal(lookAndSay(0), "0");
  });

  it("should handle input of 1", function() {
    assert.equal(lookAndSay(1), "1");
  });
});