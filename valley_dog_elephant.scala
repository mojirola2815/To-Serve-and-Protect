import scala.collection.mutable.ListBuffer

object ToServeAndProtect {

  // Data structures used to store data
  val officers: ListBuffer[Officer] = ListBuffer()
  val suspects: ListBuffer[Suspect] = ListBuffer()
  val crimeReports: ListBuffer[CrimeReport] = ListBuffer()
  val warrants: ListBuffer[Warrant] = ListBuffer()

  // Classes for objects within the system
  class Officer(val name: String, val badgeNumber: Int)

  class Suspect(val name: String, val address: String)

  class CrimeReport(val crimeType: String, val suspect: Suspect)

  class Warrant(val suspect: Suspect, val description: String)

  // Utility methods for managing cases
  def addOfficer(name: String, badgeNumber: Int): Unit = {
    officers += new Officer(name, badgeNumber)
  }

  def addSuspect(name: String, address: String): Unit = {
    suspects += new Suspect(name, address)
  }

  def addCrimeReport(crimeType: String, suspect: Suspect): Unit = {
    crimeReports += new CrimeReport(crimeType, suspect)
  }

  def addWarrant(suspect: Suspect, description: String): Unit = {
    warrants += new Warrant(suspect, description)
  }

  def assignOfficerToCrime(officer: Officer, crime: CrimeReport): Unit = {
    crime.officer = officer
    officer.assignedCrimes += crime
  }

  def serveWarrant(officer: Officer, warrant: Warrant): Unit = {
    warrant.suspect.arrested = true
    warrant.servedBy = officer
    officer.arrests += warrant
  }

  def closeCase(report: CrimeReport): Unit = {
    report.closed = true
  }

  def printOfficersAndCrimes(): Unit = {
    println("OFFICERS AND CRIMES:")
    println("===================")
    for (o <- officers) {
      println(s"Officer ${o.name}, Badge #${o.badgeNumber}:")
      if (o.assignedCrimes.isEmpty) {
        println("\tNo assigned crimes.")
      } else {
        for (c <- o.assignedCrimes) {
          println(s"\tCrime: ${c.crimeType}, Suspect: ${c.suspect.name}")
        }
      }
    }
  }

  def printArrests(): Unit = {
    println("ARRESTED SUSPECTS:")
    println("==================")
    for (a <- warrants) {
      if (a.servedBy != null) {
        println(s"${a.suspect.name} was arrested by ${a.servedBy.name}.")
      }
    }
  }

  def processCrime(officer: Officer, crime: CrimeReport, warrant: Warrant): Unit = {
    assignOfficerToCrime(officer, crime)
    serveWarrant(officer, warrant)
    closeCase(crime)
  }

  def main(args: Array[String]): Unit = {
    addOfficer("John Smith", 12345)
    addOfficer("Jane Doe", 54321)

    addSuspect("John Doe", "123 Main Street")
    addSuspect("Jane Smith", "321 Main Street")

    addCrimeReport("Robbery", suspects(0)) // John Doe
    addCrimeReport("Theft", suspects(1)) // Jane Smith

    addWarrant(suspects(0), "Robbery of 123 Main Street") // John Doe
    addWarrant(suspects(1), "Theft of 321 Main Street") // Jane Smith

    processCrime(officers(0), crimeReports(0), warrants(0)) // John Smith & John Doe
    processCrime(officers(1), crimeReports(1), warrants(1)) // Jane Doe & Jane Smith

    printOfficersAndCrimes()
    printArrests()
  }
}