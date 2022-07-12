// JavaScript for Phone Application Demo Program
// Jim Skon, Kenyon College, 2017
var operation;  // operation
var editid;

$(document).ready(function () {
    $("#search-btn").click(getMatches);
    operation = "Find School";
    $("#clear").click(clearResults);
});

// Build output table from comma delimited list
function buildTable(list) {
    var a = list.split(",");
    if (a.length < 1) {
	return "<h3>Internal Error</h3>";
    } else if (a.length == 1) {
	return "<h3>Nothing Found</h3>";
    } else {
	var result = '<table class="w3-table-all w3-hoverable" border="2"><tr><th>Subject</th><th>School</th><th>Course</th><th>Credits</th><th>Action</th><tr>';
	var aLen = a.length;
	for (var i = 1; i < aLen; i+=5) {
	    result += "<tr><td class='subject'>"+a[i]+"</td><td class='schoolName'>"+a[i+1]+"</td><td class='courseName'>"+a[i+2]+"</td><td class='credits'>"+a[i+3]+"</td>";
	    result += "<td><button type='button' ID='"+a[i+4]+"' class='btn btn-primary btn-sm edit'>Edit</button> ";
	    result += "<button type='button' ID='"+a[i+4]+"' class='btn btn-primary btn-sm delete'>Delete</button></td></tr>";
	}
	result += "</table>";

	return result;
    }
}

function processResults(results) {
    console.log("Results:"+results);
    $('#searchresults').empty();
    $('#searchresults').append(buildTable(results));
}

function clearResults() {
    $('#searchresults').empty();
}

function getMatches(){
    $('.editdata').hide();
    $('#searchresults').empty();
    $.ajax({
	url: '/cgi-bin/dailey2_CurriculumMatchingExample_CurriculumMatchingExample.cgi?find='+$('#search').val()+'&operation='+operation,
	dataType: 'text',
	success: processResults,
	error: function(){alert("Error: Something went wrong");}
    });
}
