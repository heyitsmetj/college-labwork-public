<!DOCTYPE html>
<html lang="en">
<head>
    <title>A5SetC1</title>
</head>
<body>
<hr>
<h2>1. Accept Minimum Years of Experience</h2>
<form method="POST">
    <label for="experience">Enter Minimum Experience (in years):</label>
    <input type="number" id="experience" name="experience" required>
    <input type="submit" value="Search Agents">
</form>
<hr>

<h2>2. Accept Agent Name and Display Policy Holders</h2>
<form method="POST">
    <label for="agent_name">Enter Agent Name:</label>
    <input type="text" id="agent_name" name="agent_name" required>
    <input type="submit" value="Search Policy Holders">
</form>
<hr>

<h2>3. Accept Details of New Agent</h2>
<form method="POST">
    <label for="new_agent_name">Agent Name:</label>
    <input type="text" id="new_agent_name" name="new_agent_name" required><br><br>
    <label for="new_agent_city">City:</label>
    <select id="new_agent_city" name="new_agent_city" required>
        <option value="Pune">Pune</option>
        <option value="Mumbai">Mumbai</option>
        <option value="Chennai">Chennai</option>
    </select><br><br>
    <label for="new_agent_experience">Experience (in years):</label>
    <input type="number" id="new_agent_experience" name="new_agent_experience" required><br><br>
    <input type="submit" value="Add New Agent">
</form>
<hr>

<h2>4. Display All Agent Details</h2>
<form method="POST">
    <input type="submit" name="display_all_agents" value="Display All Agents">
</form>
<hr>

</body>
</html>

<?php
$host = "localhost";
$db = "tejasSE2203";
$user = "postgres";
$pass = "12345";

$conn = pg_connect("host=$host dbname=$db user=$user password=$pass");

if (!$conn) {
    die("Database connection failed.");
}

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['experience'])) {
    $experience = intval($_POST['experience']);

    $query = "
        SELECT name, city, experience
        FROM Agents
        WHERE experience >= $1
    ";
    
    $result = pg_query_params($conn, $query, [$experience]);

    if (!$result) {
        echo "<p>Error fetching agent details.</p>";
    } else {
        echo "<h3>Agents with at least $experience years of experience:</h3>";
        echo "<table border='1' cellpadding='10' cellspacing='0'>";
        echo "<tr><th>Agent Name</th><th>City</th><th>Experience</th></tr>";

        while ($row = pg_fetch_assoc($result)) {
            echo "<tr><td>" . htmlspecialchars($row['name']) . "</td>
                  <td>" . htmlspecialchars($row['city']) . "</td>
                  <td>" . htmlspecialchars($row['experience']) . "</td></tr>";
        }

        echo "</table>";
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['agent_name'])) {
    $agent_name = $_POST['agent_name'];

    $query = "
        SELECT p.policy_id, p.policy_amount, c.name as policy_holder_name
        FROM Policies p
        JOIN Clients c ON p.policy_id = c.policy_id
        JOIN Agents a ON p.agent_id = a.agent_id
        WHERE a.name = $1
    ";

    $result = pg_query_params($conn, $query, [$agent_name]);

    if (!$result) {
        echo "<p>Error fetching policy holders for agent: $agent_name.</p>";
    } else {
        echo "<h3>Policy Holders who bought policies from $agent_name:</h3>";
        echo "<table border='1' cellpadding='10' cellspacing='0'>";
        echo "<tr><th>Policy ID</th><th>Policy Amount</th><th>Policy Holder Name</th></tr>";

        while ($row = pg_fetch_assoc($result)) {
            echo "<tr><td>" . htmlspecialchars($row['policy_id']) . "</td>
                  <td>" . htmlspecialchars($row['policy_amount']) . "</td>
                  <td>" . htmlspecialchars($row['policy_holder_name']) . "</td></tr>";
        }

        echo "</table>";
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['new_agent_name'])) {
    $new_agent_name = $_POST['new_agent_name'];
    $new_agent_city = $_POST['new_agent_city'];
    $new_agent_experience = intval($_POST['new_agent_experience']);

    $insert_query = "
        INSERT INTO Agents (name, city, experience)
        VALUES ($1, $2, $3)
    ";

    $result = pg_query_params($conn, $insert_query, [$new_agent_name, $new_agent_city, $new_agent_experience]);

    if (!$result) {
        echo "<p>Error adding new agent to the database.</p>";
    } else {
        echo "<p>New agent <strong>$new_agent_name</strong> added successfully.</p>";
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['display_all_agents'])) {
    $query = "SELECT name, city, experience FROM Agents";
    $result = pg_query($conn, $query);

    if (!$result) {
        echo "<p>Error fetching all agent details.</p>";
    } else {
        echo "<h3>All Agents:</h3>";
        echo "<table border='1' cellpadding='10' cellspacing='0'>";
        echo "<tr><th>Agent Name</th><th>City</th><th>Experience</th></tr>";

        while ($row = pg_fetch_assoc($result)) {
            echo "<tr><td>" . htmlspecialchars($row['name']) . "</td>
                  <td>" . htmlspecialchars($row['city']) . "</td>
                  <td>" . htmlspecialchars($row['experience']) . "</td></tr>";
        }

        echo "</table>";
    }
}

pg_close($conn);
?>
