<!DOCTYPE html>
<html lang="en">
<head>
    <title>A6E2SetC2</title>
    <script>
        function loadMovies() {
            var actorId = document.getElementById("actorSelect").value;

            var xhr = new XMLHttpRequest();
            xhr.open("GET", "getMovies.php?actor_id=" + actorId, true);

            xhr.onreadystatechange = function () {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    document.getElementById("movieTable").innerHTML = xhr.responseText;
                }
            };

            xhr.send();
        }
    </script>
</head>
<body>
    <h2>Search Movies by Actor</h2>

    <label for="actorSelect">Select Actor:</label>
    <select id="actorSelect" onchange="loadMovies()">
        <option value="" disabled selected>Select an actor</option>
        <option value="1">Leonardo DiCaprio</option>
        <option value="2">Tom Hanks</option>
        <option value="3">Scarlett Johansson</option>
    </select>

    <div id="movieTable" style="margin-top: 20px;"></div>
</body>
</html>
