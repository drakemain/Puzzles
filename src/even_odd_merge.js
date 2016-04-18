var List = require('./linked_list');

module.exports = function(list) {
	var counter = 0;
	var startNode = list;

	var evenNodes = [],
			oddNodes = [];

	while (list !== null) {
		if (list.value !== 0 && counter % 2 === 0) {
			console.log(list.value, 'even');
			evenNodes.push(new List(list.value));
		} else if (counter % 2 !== 0) {
			console.log(list.value, 'odd');
			oddNodes.push(new List(list.value));
		}

		counter++;
		list = list.next;
	}

	console.log(evenNodes, oddNodes);

	list = startNode;

	for (var i = 0; i < evenNodes.length; i++) {
		list.next = evenNodes[i];
		list = list.next;
		console.log(evenNodes[i]);
	}

	for (var i = 0; i < oddNodes.length; i++) {
		list.next = oddNodes[i];
		list = list.next;
	}
}