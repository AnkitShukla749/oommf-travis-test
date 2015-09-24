/* FILE: affinetransformscalarfield.h      -*-Mode: c++-*-
 *
 * Scalar field object, derived from Oxs_ScalarField class,
 * that applies an affine transformation to the output of
 * another scalar field object.
 *
 */

#ifndef _OXS_AFFINETRANSFORMSCALARFIELD
#define _OXS_AFFINETRANSFORMSCALARFIELD

#include <vector>

#include "oc.h"

#include "threevector.h"
#include "util.h"
#include "scalarfield.h"

/* End includes */

class Oxs_AffineTransformScalarField:public Oxs_ScalarField {
private:
  OC_REAL8m offset;
  OC_REAL8m multiplier;
  Oxs_OwnedPointer<Oxs_ScalarField> field;
public:
  virtual const char* ClassName() const; // ClassName() is
  /// automatically generated by the OXS_EXT_REGISTER macro.
  Oxs_AffineTransformScalarField
  (const char* name,     // Child instance id
   Oxs_Director* newdtr, // App director
   const char* argstr);  // MIF input block parameters

  virtual ~Oxs_AffineTransformScalarField();

  virtual OC_REAL8m Value(const ThreeVector& pt) const;

  virtual void FillMeshValue(const Oxs_Mesh* mesh,
			     Oxs_MeshValue<OC_REAL8m>& array) const;
  virtual void IncrMeshValue(const Oxs_Mesh* mesh,
			     Oxs_MeshValue<OC_REAL8m>& array) const;
  virtual void MultMeshValue(const Oxs_Mesh* mesh,
			     Oxs_MeshValue<OC_REAL8m>& array) const;
};


#endif // _OXS_AFFINETRANSFORMSCALARFIELD