<!DOCTYPE html>
<html lang="en">
<head>
    <title>A6E2SetA2</title>
    <script>
        function searchStudent() 
        {
            var input = document.getElementById("searchInput").value.toLowerCase();
           
            var xhr = new XMLHttpRequest();

            xhr.open("GET", "search.php?query=" + input, true);

            xhr.onreadystatechange = function() 
            {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    document.getElementById("result").innerHTML = xhr.responseText;
                }
            };
            
            xhr.send();
        }
    </script>
</head>
<body>
    <h2>Student Name Search</h2>
    <input type="text" id="searchInput" onkeyup="searchStudent()" placeholder="Type a name...">
    <div id="result" style="margin-top: 20px; border: 1px solid black; padding: 10px;"></div>
</body>
</html>
