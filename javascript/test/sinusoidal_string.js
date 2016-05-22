var chai = require('chai');
var assert = chai.assert;

var sinusoidalString = require('./../src/sinusoidal_string');

describe("Sinusoidal String", function() {
	it("should produce a sinusoidal-styled string.", function() {
		assert.equal(sinusoidalString("Hello World!"), "e lHloWrdlo!");
	})
})