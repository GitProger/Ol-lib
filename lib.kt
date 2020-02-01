private fun solve() {

}

fun main() {
    var t = 1;
    t = readInt()
    while (t-- != 0) {
        solve()
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
class yesno(y: String, n: String) {
    private val yes = y
    private val no = n
    operator fun invoke(ok: Boolean): String { return if (ok) this.yes else this.no }
}
