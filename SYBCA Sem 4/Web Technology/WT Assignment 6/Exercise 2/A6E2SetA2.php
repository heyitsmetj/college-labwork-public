<!DOCTYPE html>
<html lang="en">

<head>
    <title>A6E2SetA2</title>
    <script>
        var students = [
            "Jagdish",
            "Jaya",
            "Esha",
            "Mohan",
            "Savita",
            "Dharmesh",
            "Alka",
            "Rajesh"
        ];

        function searchStudent() {
            var input = document.getElementById("searchBox").value.toLowerCase();
            var resultDiv = document.getElementById("result");

            if (input === "") {
                resultDiv.innerHTML = "";
                return;
            }

            var matchedStudents = [];
            
            for (var i = 0; i < students.length; i++) {
                if (students[i].toLowerCase().startsWith(input)) {
                    matchedStudents.push(students[i]);
                }
            }
            
            if (matchedStudents.length > 0) {
                resultDiv.innerHTML = "<ul>";
                matchedStudents.forEach(function(student) {
                    resultDiv.innerHTML += "<li>" + student + "</li>";
                });
                resultDiv.innerHTML += "</ul>";
            } else {
                resultDiv.innerHTML = "<p>No students found.</p>";
            }
        }
    </script>
</head>

<body>
    <h2>Search Student Name</h2>
    <input type="text" id="searchBox" onkeyup="searchStudent()" placeholder="Type a name...">
    <div id="result" style="margin-top: 20px; border: 1px solid black; padding: 20px;"></div>
</body>

</html>