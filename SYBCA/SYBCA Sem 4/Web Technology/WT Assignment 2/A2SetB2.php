<!DOCTYPE html>
<html lang="en">

<head>
    <title>A2SetB2</title>
</head>

<body>
    <form action="A2SetB2.php" method="post">
        Enter a string to check its vowel count:
        <input type="text" name="string">
        <input type="submit" name="submit" value="Check">
    </form>
</body>

</html>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST["submit"])) {

        $str = $_POST["string"];

        $vowels = [
            'a' => 0,
            'e' => 0,
            'i' => 0,
            'o' => 0,
            'u' => 0,
            'Total' => 0
        ];

        echo "Your string: " . $str;
        echo "<br>Result: <br>";

        for ($i = 0; $i < strlen($str); $i++) {
            $char = $str[$i];

            if (array_key_exists(strtolower($char), $vowels)) {
                $vowels[$char]++;
                $vowels['Total']++;
            }
        }

        foreach ($vowels as $vowel => $count) {
            echo "$vowel: $count<br>";
        }
    }
}
?>