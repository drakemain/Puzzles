module.exports = function(input) {
	var output = '';

	for (var i = 1; i < input.length; i += 4) {
		output += input.substr(i, 1);
	}

	for (var i = 0; i < input.length; i += 2) {
		output += input.substr(i,1);
	}

	for (var i = 3; i < input.length; i += 4) {
		output += input.substr(i,1);
	}

	return output;
}