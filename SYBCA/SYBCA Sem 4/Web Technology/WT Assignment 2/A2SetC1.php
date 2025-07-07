<!DOCTYPE html>
<html lang="en">
<head>
    <title>A2SetC1</title>
</head>
<body>
    <h1>Email Validation</h1>
    <form action="A2SetC1.php" method="post">
        <label for="email">Enter your email:</label>
        <input type="text" id="email" name="email" required>
        <button type="submit">Submit</button>
    </form>
</body>
</html>

<?php
function validateEmail($email) {

    if (substr_count($email, '@') !== 1) {
        return "Invalid email: Must contain exactly one @ symbol.";
    }

    $parts = explode('@', $email);
    if (count($parts) !== 2) {
        return "Invalid email: Incorrect format.";
    }

    $left = $parts[0];
    $right = $parts[1];

    if (preg_match('/^[^a-zA-Z]/', $left)) {
        return "Invalid email: Local part must start with a letter.";
    }

    if (substr_count($left, '.') > 1) {
        return "Invalid email: Too many dots in the local part.";
    }

    $dotCount = substr_count($right, '.');
    if ($dotCount < 1 || $dotCount > 2) {
        return "Invalid email: Domain part must contain one or two dots.";
    }

    if (!preg_match('/^[a-zA-Z][a-zA-Z0-9._%+-]*@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/', $email)) {
        return "Invalid email: Does not match the standard email format.";
    }

    return "Valid email.";
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') 
{
    $email = $_POST['email'];
    $result = validateEmail($email);
    
    echo "<h2>Validation Result</h2>";
    echo "<p>$result</p>";
}
?>
