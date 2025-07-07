<!DOCTYPE html>
<html lang="en">
<head>
    <title>A6E2SetB1</title>
    <script>
        function loadCatalog() {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "cd_catalog.xml", true);

            xhr.onreadystatechange = function() {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    displayCatalog(xhr);
                }
            };

            xhr.send();
        }

        function displayCatalog(xhr) {
            var xmlDoc = xhr.responseXML;
            var cds = xmlDoc.getElementsByTagName("CD");
            var dropdown = document.getElementById("cdDropdown");

            for (var i = 0; i < cds.length; i++) {
                var title = cds[i].getElementsByTagName("TITLE")[0].textContent;
                var option = document.createElement("option");
                option.text = title;
                option.value = i;
                dropdown.add(option);
            }
        }

        function showDetails() 
        {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "cd_catalog.xml", true);

            xhr.onreadystatechange = function() {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    var xmlDoc = xhr.responseXML;
                    var cds = xmlDoc.getElementsByTagName("CD");
                    var index = document.getElementById("cdDropdown").value;
                    var cd = cds[index];
                    
                    var details = "<b>Title:</b> " + cd.getElementsByTagName("TITLE")[0].textContent + "<br>" +
                                   "<b>Artist:</b> " + cd.getElementsByTagName("ARTIST")[0].textContent + "<br>" +
                                   "<b>Country:</b> " + cd.getElementsByTagName("COUNTRY")[0].textContent + "<br>" +
                                   "<b>Company:</b> " + cd.getElementsByTagName("COMPANY")[0].textContent + "<br>" +
                                   "<b>Price:</b> " + cd.getElementsByTagName("PRICE")[0].textContent + "<br>" +
                                   "<b>Year:</b> " + cd.getElementsByTagName("YEAR")[0].textContent;
                    document.getElementById("details").innerHTML = details;
                }
            };
            xhr.send();
        }
    </script>
</head>
<body onload="loadCatalog()">
    <h2>CD Catalog</h2>
    <select id="cdDropdown" onchange="showDetails()">
        <option value="" disabled selected>Select a CD</option>
    </select>
    <div id="details" style="margin-top: 20px; border: 1px solid black; padding: 10px;"></div>
</body>
</html>
