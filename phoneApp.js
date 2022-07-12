// JavaScript for Phone Application Demo Program
// Jim Skon, Kenyon College, 2017
var operation;  // operation
var editid;

$(document).ready(function () {
    $("#search-btn").click(getMatches);
    operation = "Find School";
    $("#clear").click(clearResults);
});

changeOperation(operation);

function changeOperation(operation){
    if(operation=="Add Entry"){
	console.log("Add Entry");
	$('#addmessage').empty();
	$('.inputdata').show();
	$('.searchbox').hide();
	$('.results').hide();
	$('.editdata').hide();}
    else{
	console.log("not add entry");
	$('.editdata').hide();
	$('.inputdata').hide();
	$('.results').show();
	$('.searchbox').show();
    }
}

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

function processEdit(){
    console.log("edit data");
    $('#searchresults').empty();
    $('.editdata').show();
    $("#edit-btn").click(editEntry);
    console.log("Edit Record: " + $(this).attr('ID'));
    var row=$(this).parents("tr");
    console.log("Subject: "+ $(row).find('.subject').text()+":"+$(row).find('.type').text());
    editid=$(this).attr('ID');

    $('#editsubject').val( $(row).find('.subject').text());
    $('#editschoolname').val( $(row).find('.schoolName').text());
    $('#editcoursename').val( $(row).find('.courseName').text());
    $('#editcredits').text( $(row).find('.credits').text());
}

function editDone() {
    $('#editmessage').text($('#editsubject').val()+" "+$('#editschoolname').val()+ " SAVED");
}
function editEntry(){
    console.log("Attempting to edit an entry");
    console.log("Subject:" + $('#editsubject').val() + "ID:" + editid);
    $('#searchresults').empty();
    $.ajax({
	url: '/cgi-bin/dailey2_phoneAppComplete.cgi?editid='+editid +'&editsubject='+$('#editsubject').val()+'&editschoolname='+$('#editschoolname').val()+'&editcoursename='+$('#editcoursename').val()+'&editcredits='+$('#editcredits').text()+'&operation=edit',
	dataType: 'text',
	success: editDone(),
	error: function(){alert("Error: Something went wrong");}
    });
}


function processDelete(){
    console.log("Attempting to delete an entry");
    $('#searchresults').empty();
    var id=$(this).attr('ID');
    $.ajax({
	url: '/cgi-bin/dailey2_phoneAppComplete.cgi?deleteid='+$(this).attr('ID')+'&operation=delete',
	dataType: 'text',
	success: function(){alert("Deleted Record: " +id );},
	error: function(){alert("Error: Something went wrong");}
    });
}
function processResults(results) {
    console.log("Results:"+results);
    $('#searchresults').empty();
    $('#searchresults').append(buildTable(results));
    $(".edit").click(processEdit);
    $(".delete").click(processDelete);
}

function clearResults() {
    $('#searchresults').empty();
}

function getMatches(){
    $('.editdata').hide();
    $('#searchresults').empty();
    $.ajax({
	url: '/cgi-bin/dailey2_phoneAppComplete.cgi?find='+$('#search').val()+'&operation='+operation,
	dataType: 'text',
	success: processResults,
	error: function(){alert("Error: Something went wrong");}
    });
}

function processAdd(results) {
    $('#addmessage').empty();
    console.log("Add:",results);
    $('#addmessage').text($('#addsubject').val()+" "+$('#addschoolname').val()+ " ADDED");
    $('#addsubject').val('');
    $('#addschoolname').val('');
    $('#addcoursename').val('');

}

function addEntry(){
    console.log("Attempting to add an entry");
    console.log("Subject:" + $('#addsubject').val());
    $('#searchresults').empty();
    $.ajax({
	url: '/cgi-bin/dailey2_phoneAppComplete.cgi?asubject='+$('#addsubject').val()+'&aschoolname='+$('#addschoolname').val()+'&acoursename='+$('#coursename').val()+'&acredits='+$('#addcredits').text()+'&operation='+operation,
	dataType: 'text',
	success: processAdd,
	error: function(){alert("Error: Something went wrong");}
    });
}
