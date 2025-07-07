<!DOCTYPE html>
<html lang="en">
<head>
    <title>A6E2SetC1</title>
    <script>
        function loadTeachers() {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "getTeachers.php", true);

            xhr.onreadystatechange = function () {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    displayTeachers(JSON.parse(xhr.responseText));
                }
            };

            xhr.send();
        }

        function displayTeachers(data) {
            var table = "<table border='1' cellpadding='10' cellspacing='0' style='width: 100%; text-align: left;'>";
            table += "<tr><th>Teacher No</th><th>Name</th><th>Subject</th><th>Research Area</th></tr>";

            data.forEach(function (teacher) {
                table += "<tr>";
                table += "<td>" + teacher.tno + "</td>";
                table += "<td>" + teacher.name + "</td>";
                table += "<td>" + teacher.subject + "</td>";
                table += "<td>" + teacher.research_area + "</td>";
                table += "</tr>";
            });

            table += "</table>";
            document.getElementById("teacherTable").innerHTML = table;
        }
    </script>
</head>
<body>
    <h2>Teacher Information</h2>
    <button onclick="loadTeachers()">Print</button>
    <div id="teacherTable" style="margin-top: 20px;"></div>
</body>
</html>
