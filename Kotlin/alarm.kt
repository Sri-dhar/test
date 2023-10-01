fun main()
{
    val alarm : Int = 23;
    when(alarm)
    {
        in 1..120 -> println("the time is $alarm")
        // 12-> println("The time is 12")
        // 23-> println("The time is 23")
    }
}