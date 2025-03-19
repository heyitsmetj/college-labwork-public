<!DOCTYPE html>
<html lang="en">
<head>
    <title>Contact List</title>
    <script>
        function readContacts() {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "contact.dat", true);

            xhr.onreadystatechange = function () {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    displayContacts(xhr.responseText);
                }
            };

            xhr.send();
        }

        function displayContacts(data) {
            var lines = data.split("\n");
            var table = "<table border='1' cellpadding='10' cellspacing='0' style='width: 100%; text-align: left;'>";
            table += "<tr><th>Sr No</th><th>Name</th><th>Residence Number</th><th>Mobile Number</th><th>Relation</th></tr>";

            for (var i = 0; i < lines.length; i++) {
                var contact = lines[i].split(",");
                table += "<tr>";
                for (var j = 0; j < contact.length; j++) {
                    table += "<td>" + contact[j] + "</td>";
                }
                table += "</tr>";
            }

            table += "</table>";
            document.getElementById("contactTable").innerHTML = table;
        }
    </script>
</head>
<body>
    <h2>Contact List</h2>
    <button onclick="readContacts()">Print</button>
    <div id="contactTable" style="margin-top: 20px;"></div>
</body>
</html>
