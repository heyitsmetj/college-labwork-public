<?php

$host = "localhost";
$db = "tejasSE2203";
$user = "postgres";
$pass = "12345";

$conn = pg_connect("host=$host dbname=$db user=$user password=$pass");

if (!$conn) {
    die("Database connection failed.");
}

$actor_id = $_GET['actor_id'] ?? '';

$query = "SELECT mname, release_year FROM Movie WHERE ano = $actor_id";
$result = pg_query($conn, $query);

if (!$result) {
    echo "Error fetching data.";
    exit;
}

if (pg_num_rows($result) > 0) {
    echo "<table border='1' cellpadding='10' cellspacing='0'>";
    echo "<tr><th>Movie Name</th><th>Release Year</th></tr>";
    while ($row = pg_fetch_assoc($result)) {
        echo "<tr>";
        echo "<td>{$row['mname']}</td>";
        echo "<td>{$row['release_year']}</td>";
        echo "</tr>";
    }
    echo "</table>";
} else {
    echo "<p>No movies found for this actor.</p>";
}

pg_close($conn);
?>
