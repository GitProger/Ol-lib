import java.math.*
import kotlin.math.*

fun solve() {

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


fun prefixFunction(s: String): Array<Int> {
    val n = s.length
    val p = Array(n) {0}
    for (i in 1 until n) {
        var j = p[i - 1]
        while (j > 0 && s[j] != s[i])
            j = p[j - 1]
        if (s[i] == s[j])
            j++
        p[i] = j
    }
    return p
}

fun KnuthMorris(s: String, t: String): Int {
    val p = prefixFunction("$s#$t")
    val n = s.length
    val m = t.length
    for (i in n + 1 .. n + m)
        if (p[i] == n)
            return i - n - n
    return -1
}
