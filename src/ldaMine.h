#ifndef _MAIN_H_
	#define _MAIN_H_
#include "main.h"
#endif
using namespace cv;

class  LDAMine
{
    public:
        // Initializes a LDA with num_components (default 0) and specifies how
        // samples are aligned (default dataAsRow=true).
        LDAMine(int num_components = 0) :
            _num_components(num_components) {};

        // Initializes and performs a Discriminant Analysis with Fisher's
        // Optimization Criterion on given data in src and corresponding labels
        // in labels. If 0 (or less) number of components are given, they are
        // automatically determined for given data in computation.
        LDAMine(const Mat& src, vector<int> labels,
                int num_components = 0) :
                    _num_components(num_components)
        {
            this->compute(src, labels); //! compute eigenvectors and eigenvalues
        }

        // Initializes and performs a Discriminant Analysis with Fisher's
        // Optimization Criterion on given data in src and corresponding labels
        // in labels. If 0 (or less) number of components are given, they are
        // automatically determined for given data in computation.
        LDAMine(InputArrayOfArrays src, InputArray labels,
                int num_components = 0) :
                    _num_components(num_components)
        {
            this->compute(src, labels); //! compute eigenvectors and eigenvalues
        }

        // Serializes this object to a given filename.
        void save(const string& filename) const;

        // Deserializes this object from a given filename.
        void load(const string& filename);

        // Serializes this object to a given cv::FileStorage.
        void save(FileStorage& fs) const;

            // Deserializes this object from a given cv::FileStorage.
        void load(const FileStorage& node);

        // Destructor.
        ~LDAMine() {}

        //! Compute the discriminants for data in src and labels.
        void compute(InputArrayOfArrays src, InputArray labels);

        // Projects samples into the LDA subspace.
        Mat project(InputArray src);

        // Reconstructs projections from the LDA subspace.
        Mat reconstruct(InputArray src);

        // Returns the eigenvectors of this LDA.
        Mat eigenvectors() const { return _eigenvectors; };

        // Returns the eigenvalues of this LDA.
        Mat eigenvalues() const { return _eigenvalues; }

    protected:
        bool _dataAsRow;
        int _num_components;
        Mat _eigenvectors;
        Mat _eigenvalues;

        void lda(InputArrayOfArrays src, InputArray labels);
};
