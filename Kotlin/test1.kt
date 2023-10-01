fun main() {
    print("Enter the first number: ")
    val input1 = readLine()
    print("Enter the second number: ")
    val input2 = readLine()

    if (input1 != null && input2 != null) {
        val variable = input1.toIntOrNull()
        val variable2 = input2.toIntOrNull()

        if (variable != null && variable2 != null) {
            val sum = variable + variable2
            println("The sum of $variable and $variable2 is $sum")
        } else {
            println("Invalid input. Please enter valid numbers.")
        }
    } else {
        println("Invalid input. Please enter valid numbers.")
    }
}
