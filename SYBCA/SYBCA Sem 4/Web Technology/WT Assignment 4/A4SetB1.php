<?php

abstract class Account
{
    protected $Acc_Holder_Name;
    protected $Acc_Holder_Contact_No;

    public function __construct($name, $contact)
    {
        $this->Acc_Holder_Name = $name;
        $this->Acc_Holder_Contact_No = $contact;
    }

    abstract public function displayInfo();
    abstract public function deposit($amount);
    abstract public function withdraw($amount);
    abstract public function checkbal();
    abstract public function getAccNo();
    abstract public function calculateInterest();
}

class Saving_Account extends Account
{
    private $S_Acc_No;
    private $balance;

    public function __construct($name, $contact, $accNo, $initialbal)
    {
        parent::__construct($name, $contact);
        $this->S_Acc_No = $accNo;
        $this->balance = $initialbal;
    }

    public function deposit($amount)
    {
        $this->balance += $amount;
        echo "Deposited Rs. " . $amount . " into Savings Account<br>";
    }

    public function withdraw($amount)
    {
        if ($this->balance - $amount >= 2000) {
            $this->balance -= $amount;
            echo "Withdrawn Rs. " . $amount . " from Savings Account<br>";
        } else {
            echo "Insufficient balance for withdrawal in Savings Account<br>";
        }
    }

    public function checkbal()
    {
        if ($this->balance < 2000) {
            $this->balance -= 500;
            echo "Service charge of Rs. 500 imposed due to low balance in Savings Account<br>";
        }
    }

    public function calculateInterest()
    {
        $interest = 0.10 * $this->balance;
        $this->balance += $interest;
        echo "Interest Rs. " . $interest . " added to Savings Account<br>";
    }

    public function displayInfo()
    {
        echo "\nAccount Type: Saving Account<br>";
        echo "Account Holder: " . $this->Acc_Holder_Name . "<br>";
        echo "Contact No: " . $this->Acc_Holder_Contact_No . "<br>";
        echo "Account Number: " . $this->S_Acc_No . "<br>";
        echo "balance: Rs. " . $this->balance . "<br>";
    }

    public function getAccNo()
    {
        return $this->S_Acc_No;
    }
}

class Current_Account extends Account
{
    private $C_Acc_No;
    private $balance;

    public function __construct($name, $contact, $accNo, $initialbal)
    {
        parent::__construct($name, $contact);
        $this->C_Acc_No = $accNo;
        $this->balance = $initialbal;
    }

    public function deposit($amount)
    {
        $this->balance += $amount;
        echo "Deposited Rs. " . $amount . " into Current Account<br>";
    }

    public function withdraw($amount)
    {
        if ($this->balance - $amount >= 5000) {
            $this->balance -= $amount;
            echo "Withdrawn Rs. " . $amount . " from Current Account<br>";
            $this->checkbal();
        } else {
            echo "Insufficient balance for withdrawal in Current Account<br>";
            $this->checkbal();
        }
    }

    public function checkbal()
    {
        if ($this->balance < 5000) {
            $this->balance -= 1000;
            echo "Service charge of Rs. 1000 imposed due to low balance in Current Account<br>";
        }
    }

    public function calculateInterest()
    {
        echo "No interest applicable for Current Account.<br>";
    }

    public function displayInfo()
    {
        echo "\nAccount Type: Current Account<br>";
        echo "Account Holder: " . $this->Acc_Holder_Name . "<br>";
        echo "Contact No: " . $this->Acc_Holder_Contact_No . "<br>";
        echo "Account Number: " . $this->C_Acc_No . "<br>";
        echo "balance: Rs. " . $this->balance . "<br>";
    }

    public function getAccNo()
    {
        return $this->C_Acc_No;
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
    $name = $_POST['name'];
    $contact = $_POST['contact'];
    $account_type = $_POST['account_type'];
    $acc_no = $_POST['acc_no'];
    $balance = $_POST['balance'];

    $account = null;

    if ($account_type == 'saving') {
        $account = new Saving_Account($name, $contact, $acc_no, $balance);
    } elseif ($account_type == 'current') {
        $account = new Current_Account($name, $contact, $acc_no, $balance);
    }

    if ($account) {
        $account->displayInfo();
    } else {
        echo "Invalid account type.";
    }
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>A4SetB1</title>
</head>
<body>
    <h2>Create Bank Account</h2>
    <form action="A4SetB1.php" method="POST">
        <label for="name">Account Holder's Name:</label>
        <input type="text" id="name" name="name" required><br><br>

        <label for="contact">Account Holder's Contact Number:</label>
        <input type="number" id="contact" name="contact" required><br><br>

        <label for="account_type">Choose Account Type:</label>
        <select name="account_type" id="account_type" required>
            <option value="saving">Saving Account</option>
            <option value="current">Current Account</option>
        </select><br><br>

        <label for="acc_no">Account Number:</label>
        <input type="number" id="acc_no" name="acc_no" required><br><br>

        <label for="balance">Initial balance (Rs.):</label>
        <input type="number" id="balance" name="balance" required><br><br>

        <input type="submit" value="Create Account">
    </form>
</body>
</html>
