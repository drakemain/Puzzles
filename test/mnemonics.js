"use_strict";

var chai = require('chai');
var assert = chai.assert;

var mnemonics = require('./../src/mnemonics');

describe("Mnemonics", function() {
  it.skip("should produce correct mnemonics for 37", function() {
    var expect = [
      "DP",
      "DQ",
      "DR",
      "DS",
      "EP",
      "EQ",
      "ER",
      "ES",
      "FP",
      "FQ",
      "FR",
      "FS"
    ];

    assert.deepEqual(mnemonics("37"), expect);
  });
  it.skip("should produce correct mnemonics for 234", function() {
    var expect = [
      "ADG",
      "ADH",
      "ADI",
      "AEG",
      "AEH",
      "AEI",
      "AFG",
      "AFH",
      "AFI",
      "BDG",
      "BDH",
      "BDI",
      "BEG",
      "BEH",
      "BEI",
      "BFG",
      "BFH",
      "BFI",
      "CDG",
      "CDH",
      "CDI",
      "CEG",
      "CEH",
      "CEI",
      "CFG",
      "CFH",
      "CFI"
    ];

    assert.deepEqual(mnemonics("234"), expect);
  });
});