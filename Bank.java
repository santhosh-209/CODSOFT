import java.util.Scanner;
class BankAccount
{
    private double balance;
    public BankAccount(double initialBalance) 
    {
        this.balance = initialBalance;
    }
    public double getBalance() 
    {
        return balance;
    }

    public void deposit(double amount) {
        if (amount > 0)
        {
            balance += amount;
            System.out.println("Deposited: $" + amount);
	    System.out.println("Total amount in account" +balance);
        } 
	else
        {
            System.out.println("Invalid deposit amount.");
        }
    }

    public boolean withdraw(double amount) 
    {
        if (amount > 0 && amount <= balance) 
        {
            balance -= amount;
            System.out.println("Withdrawn: $" + amount);
	    System.out.println("Total amount in account" +balance);

            return true;
        } else 
        {
            System.out.println("Insufficient balance or invalid amount.");
            return false;
        }
    }
}
class ATM 
{
    private BankAccount account;

    public ATM(BankAccount account)
    {
        this.account = account;
    }

    public void withdraw(double amount) {
        if (account.withdraw(amount))
        {
            System.out.println("Please take your cash.");
        }
    }

    public void deposit(double amount) {
        account.deposit(amount);
        }

    public void checkBalance()
    {
        System.out.println("Your current balance is: $" + account.getBalance());
    }
}
public class Bank
{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BankAccount account = new BankAccount(1000); // Initial balance
        ATM atm = new ATM(account);

        while (true) {
            System.out.println("\nATM Menu:");
            System.out.println("1. Withdraw");
            System.out.println("2. Deposit");
            System.out.println("3. Check Balance");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter amount to withdraw: ");
                    double withdrawAmount = scanner.nextDouble();
                    atm.withdraw(withdrawAmount);
                    break;
                case 2:
                    System.out.print("Enter amount to deposit: ");
                    double depositAmount = scanner.nextDouble();
                    atm.deposit(depositAmount);
                    break;
                case 3:
                    atm.checkBalance();
                    break;
                case 4:
                    System.out.println("Thank you for using the ATM. Goodbye!");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid option. Please try again.");
                    break;
            }
        }
    }
}