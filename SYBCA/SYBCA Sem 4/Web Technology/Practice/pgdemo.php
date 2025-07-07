<?php
$host = "localhost";
$dbname = "real_estate";
$user = "postgres";
$password = "12345";

$conn = pg_connect("host=$host dbname=$dbname user=$user password=$password");

if (!$conn) {
    die("Connection failed: " . pg_last_error());
}

if (isset($_POST['owner_name'])) {
    $owner_name = $_POST['owner_name'];

    $sql = "SELECT p.pno, p.description, p.area
            FROM properties p
            JOIN owners o ON p.owner_id = o.id
            WHERE o.oname = $1";

    $result = pg_query_params($conn, $sql, array($owner_name));

    if ($result) {
        if (pg_num_rows($result) > 0) 
        {
            echo "<h3>Properties owned by $owner_name:</h3>";
            while ($row = pg_fetch_assoc($result)) 
            {
                echo "Property No: " . $row['pno'] . "<br>";
                echo "Description: " . $row['description'] . "<br>";
                echo "Area: " . $row['area'] . " sq. meters<br><br>";
            }
        } 
        else 
        {
            echo "No properties found for the owner $owner_name.";
        }
    } 
    else 
    {
        echo "Error executing query: " . pg_last_error($conn);
    }
}

?>

<form method="post" action="">
    <label for="owner_name">Enter Owner Name:</label>
    <input type="text" id="owner_name" name="owner_name" required>
    <input type="submit" value="Search">
</form>

<?php
pg_close($conn);
?>