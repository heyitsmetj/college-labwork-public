<?php

$host = "localhost";
$db = "tejasSE2203";
$user = "postgres";
$pass = "12345";

$conn = pg_connect("host=$host dbname=$db user=$user password=$pass");

if (!$conn) {
    die("Database connection failed.");
}

$query = "SELECT * FROM Teacher";
$result = pg_query($conn, $query);

if (!$result) {
    echo json_encode(["error" => "Error fetching data."]);
    exit;
}

$teachers = [];
while ($row = pg_fetch_assoc($result)) {
    $teachers[] = [
        "tno" => $row['tno'],
        "name" => $row['name'],
        "subject" => $row['subject'],
        "research_area" => $row['research_area']
    ];
}

pg_close($conn);

echo json_encode($teachers);
?>
