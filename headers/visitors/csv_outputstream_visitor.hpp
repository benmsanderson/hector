#ifndef CSV_OUTPUTSTREAM_VISITOR_H
#define CSV_OUTPUTSTREAM_VISITOR_H
/*
 *  csv_outputstream_visitor.h
 *  hector
 *
 *  Created by Ben on 1 March 2011.
 *
 */

#include <string>

#include "visitors/avisitor.hpp"

#define DELIMITER ","

/*! \brief A visitor which will report all results at each model period.
 */
class CSVOutputStreamVisitor : public AVisitor {
public:
    CSVOutputStreamVisitor( std::ostream& outputStream, const bool printHeader = true );
    ~CSVOutputStreamVisitor();
    
    virtual bool shouldVisit( const bool in_spinup, const double date );
    
    virtual void visit( Core* c );
    virtual void visit( ForcingComponent* c );
    virtual void visit( SimpleNbox* c );
    virtual void visit( HalocarbonComponent* c );
    virtual void visit( TemperatureComponent* c );
    virtual void visit( BlackCarbonComponent* c );
    virtual void visit( OrganicCarbonComponent* c );
    virtual void visit( slrComponent* c );
    virtual void visit( OceanComponent* c );
    virtual void visit( OzoneComponent* c );
	
private:
    //! The file output stream in which the csv output will be written to.
    std::ostream& csvFile;
    
    // Data retained while the visitor is operating
    double current_date;
    
    // Spin up Flag
    bool in_spinup;
        
    //! Current model date, stored as a string for output
    std::string datestring;
    
    //! Current model mode, stored as a string for output
    std::string spinupstring;
    
    //! Name of current run
    std::string run_name;
    
    //! Helper function: prints beginning of each output line
    std::string linestamp() ;

    //! pointers to other components and stuff
    Core*             core;
};

#endif // CSV_OUTPUTSTREAM_VISITOR_H