<!DOCTYPE html>
<html lang="en">

<head>
    <title>A6E2SetA1</title>
    <script>
        function readFile() {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "sample.txt", true);
            xhr.onreadystatechange = function() {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    document.getElementById("fileContent").innerText = xhr.responseText;
                }
            };
            xhr.send();
        }
    </script>
</head>

<body>
    <h2>Click to Print the Text File Content</h2>
    <button onclick="readFile()">Print</button>
    <div id="fileContent" style="margin-top: 20px; border: 1px solid black; padding: 10px;"></div>
</body>

</html>