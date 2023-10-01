fun main(args: Array<String>) {
    if (args.isNotEmpty()) {
        val filename = args[0]
        val kotlinFile = "$filename.kt"
        val jarFile = "$filename.jar"

        val compileProcess = ProcessBuilder("kotlinc", kotlinFile, "-include-runtime", "-d", jarFile)
        val compilation = compileProcess.inheritIO().start()
        val compilationExitCode = compilation.waitFor()

        if (compilationExitCode == 0) {
            val runProcess = ProcessBuilder("java", "-jar", jarFile)
            val execution = runProcess.inheritIO().start()
            val executionExitCode = execution.waitFor()
            if (executionExitCode == 0) {
                println("Program executed successfully.")
            } else {
                println("Program execution failed with exit code $executionExitCode.")
            }
        } else {
            println("Compilation failed with exit code $compilationExitCode.")
        }
    } else {
        println("Please provide a filename as an argument.")
    }
}
