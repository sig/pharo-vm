/* Automatically generated by
	VMPluginCodeGenerator * VMMaker.oscog-EstebanLorenzano.781, VMMaker.oscog-eem.810 uuid: ffd1e591-7b0b-41f8-a01f-8ca90622208f
   from
	SoundGenerationPlugin * VMMaker.oscog-EstebanLorenzano.781, VMMaker.oscog-eem.810 uuid: ffd1e591-7b0b-41f8-a01f-8ca90622208f
	AbstractSound Sound-GuillermoPolito.69 uuid: ab9cfd18-4610-4306-ae3d-5b258f0baed3
 */
static char __buildInfo[] = "SoundGenerationPlugin * VMMaker.oscog-EstebanLorenzano.781, VMMaker.oscog-eem.810 uuid: ffd1e591-7b0b-41f8-a01f-8ca90622208f\n\
AbstractSound Sound-GuillermoPolito.69 uuid: ab9cfd18-4610-4306-ae3d-5b258f0baed3 " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "SoundGenerationPlugin.h"
#include "sqMemoryAccess.h"


/*** Proxy Functions ***/
#if defined(SQUEAK_BUILTIN_PLUGIN)
extern sqInt stackValue(sqInt offset);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt failed(void);
# define successFlag (!failed())
extern sqInt success(sqInt aBoolean);
extern void * arrayValueOf(sqInt oop);
extern void * fetchArrayofObject(sqInt fieldIndex, sqInt objectPointer);
extern double fetchFloatofObject(sqInt fieldIndex, sqInt objectPointer);
extern sqInt fetchIntegerofObject(sqInt fieldIndex, sqInt objectPointer);
extern double floatValueOf(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt pushInteger(sqInt integerValue);
extern sqInt sizeOfSTArrayFromCPrimitive(void *cPtr);
extern sqInt storeIntegerofObjectwithValue(sqInt index, sqInt oop, sqInt integer);
extern sqInt primitiveFail(void);
#else /* SQUEAK_BUILTIN_PLUGIN */
# define stackValue(i) (interpreterProxy->stackValue(i))
# define stackIntegerValue(i) (interpreterProxy->stackIntegerValue(i))
# define successFlag (!interpreterProxy->failed())
# define success(bool) (interpreterProxy->success(bool))
# define arrayValueOf(oop) (interpreterProxy->arrayValueOf(oop))
# define fetchArrayofObject(idx,oop) (interpreterProxy->fetchArrayofObject(idx,oop))
# define fetchFloatofObject(idx,oop) (interpreterProxy->fetchFloatofObject(idx,oop))
# define fetchIntegerofObject(idx,oop) (interpreterProxy->fetchIntegerofObject(idx,oop))
# define floatValueOf(oop) (interpreterProxy->floatValueOf(oop))
# define pop(n) (interpreterProxy->pop(n))
# define pushInteger(n) (interpreterProxy->pushInteger(n))
# define sizeOfSTArrayFromCPrimitive(cPtr) (interpreterProxy->sizeOfSTArrayFromCPrimitive(cPtr))
# define storeIntegerofObjectwithValue(idx,oop,value) (interpreterProxy->storeIntegerofObjectwithValue(idx,oop,value))
# define primitiveFail() interpreterProxy->primitiveFail()
#endif /* SQUEAK_BUILTIN_PLUGIN */

/* allows accessing Strings in both C and Smalltalk */
#define asciiValue(c) c



/*** Constants ***/
#define IncrementFractionBits 16
#define LoopIndexFractionMask 0x1FF
#define LoopIndexScaleFactor 0x200
#define ScaledIndexOverflow 0x20000000
#define ScaleFactor 0x8000


/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"SoundGenerationPlugin * VMMaker.oscog-EstebanLorenzano.781, VMMaker.oscog-eem.810 (i)"
#else
	"SoundGenerationPlugin * VMMaker.oscog-EstebanLorenzano.781, VMMaker.oscog-eem.810 (e)"
#endif
;


/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
EXPORT(const char*) getModuleName(void);
static sqInt halt(void);
static sqInt msg(char *s);
EXPORT(sqInt) primitiveApplyReverb(void);
EXPORT(sqInt) primitiveMixFMSound(void);
EXPORT(sqInt) primitiveMixLoopedSampledSound(void);
EXPORT(sqInt) primitiveMixPluckedSound(void);
EXPORT(sqInt) primitiveMixSampledSound(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);



/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine *
getInterpreter(void)
{
	// InterpreterPlugin>>#getInterpreter
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*)
getModuleName(void)
{
	// InterpreterPlugin>>#getModuleName
	return moduleName;
}

static sqInt
halt(void)
{
	// InterpreterPlugin>>#halt
	;
	return 0;
}

static sqInt
msg(char *s)
{
	// InterpreterPlugin>>#msg:
	fprintf(stderr, "\n%s: %s", moduleName, s);
	return 0;
}

EXPORT(sqInt)
primitiveApplyReverb(void)
{
	// ReverbSound>>#primitiveApplyReverb
    short int *aSoundBuffer;
    sqInt bufferIndex;
    sqInt bufferSize;
    sqInt delayedLeft;
    sqInt delayedRight;
    sqInt i;
    sqInt j;
    short int *leftBuffer;
    sqInt n;
    sqInt out;
    sqInt rcvr;
    short int *rightBuffer;
    sqInt sliceIndex;
    sqInt startIndex;
    sqInt tapCount;
    int *tapDelays;
    sqInt tapGain;
    int *tapGains;
    sqInt tapIndex;

	rcvr = stackValue(3);
	aSoundBuffer = arrayValueOf(stackValue(2));
	aSoundBuffer -= 1;
	startIndex = stackIntegerValue(1);
	n = stackIntegerValue(0);
	tapDelays = fetchArrayofObject(7, rcvr);
	tapDelays -= 1;
	tapGains = fetchArrayofObject(8, rcvr);
	tapGains -= 1;
	tapCount = fetchIntegerofObject(9, rcvr);
	bufferSize = fetchIntegerofObject(10, rcvr);
	bufferIndex = fetchIntegerofObject(11, rcvr);
	leftBuffer = fetchArrayofObject(12, rcvr);
	leftBuffer -= 1;
	rightBuffer = fetchArrayofObject(13, rcvr);
	rightBuffer -= 1;
	if (!successFlag) {
		return null;
	}
	for (sliceIndex = startIndex; sliceIndex < (startIndex + n); sliceIndex += 1) {
		delayedLeft = (delayedRight = 0);
		for (tapIndex = 1; tapIndex <= tapCount; tapIndex += 1) {
			i = bufferIndex - (tapDelays[tapIndex]);
			if (i < 1) {
				i += bufferSize;
			}
			tapGain = tapGains[tapIndex];
			delayedLeft += tapGain * (leftBuffer[i]);
			delayedRight += tapGain * (rightBuffer[i]);
		}
		j = (2 * sliceIndex) - 1;
		out = (aSoundBuffer[j]) + (delayedLeft / ScaleFactor);
		if (out > 0x7FFF) {
			out = 0x7FFF;
		}
		if (out < -32767) {
			out = -32767;
		}
		aSoundBuffer[j] = out;
		leftBuffer[bufferIndex] = out;
		j += 1;
		out = (aSoundBuffer[j]) + (delayedRight / ScaleFactor);
		if (out > 0x7FFF) {
			out = 0x7FFF;
		}
		if (out < -32767) {
			out = -32767;
		}
		aSoundBuffer[j] = out;
		rightBuffer[bufferIndex] = out;
		bufferIndex = (bufferIndex % bufferSize) + 1;
	}
	if (!successFlag) {
		return null;
	}
	storeIntegerofObjectwithValue(11, rcvr, bufferIndex);
	pop(3);
}


/*	Play samples from a wave table by stepping a fixed amount through the
	table on every sample. The table index and increment are scaled to allow
	fractional increments for greater pitch accuracy.
 */
/*	(FMSound pitch: 440.0 dur: 1.0 loudness: 0.5) play */

EXPORT(sqInt)
primitiveMixFMSound(void)
{
	// FMSound>>#primitiveMixFMSound
    short int *aSoundBuffer;
    sqInt count;
    sqInt doingFM;
    sqInt i;
    sqInt lastIndex;
    sqInt leftVol;
    sqInt n;
    sqInt normalizedModulation;
    sqInt offset;
    sqInt rcvr;
    sqInt rightVol;
    sqInt s;
    sqInt sample;
    sqInt scaledIndex;
    sqInt scaledIndexIncr;
    sqInt scaledOffsetIndex;
    sqInt scaledOffsetIndexIncr;
    sqInt scaledVol;
    sqInt scaledVolIncr;
    sqInt scaledVolLimit;
    sqInt scaledWaveTableSize;
    sqInt sliceIndex;
    sqInt startIndex;
    short int *waveTable;

	rcvr = stackValue(5);
	n = stackIntegerValue(4);
	aSoundBuffer = arrayValueOf(stackValue(3));
	aSoundBuffer -= 1;
	startIndex = stackIntegerValue(2);
	leftVol = stackIntegerValue(1);
	rightVol = stackIntegerValue(0);
	scaledVol = fetchIntegerofObject(3, rcvr);
	scaledVolIncr = fetchIntegerofObject(4, rcvr);
	scaledVolLimit = fetchIntegerofObject(5, rcvr);
	count = fetchIntegerofObject(7, rcvr);
	waveTable = fetchArrayofObject(8, rcvr);
	waveTable -= 1;
	scaledWaveTableSize = fetchIntegerofObject(9, rcvr);
	scaledIndex = fetchIntegerofObject(10, rcvr);
	scaledIndexIncr = fetchIntegerofObject(11, rcvr);
	normalizedModulation = fetchIntegerofObject(14, rcvr);
	scaledOffsetIndex = fetchIntegerofObject(15, rcvr);
	scaledOffsetIndexIncr = fetchIntegerofObject(16, rcvr);
	if (!successFlag) {
		return null;
	}
	doingFM = (normalizedModulation != 0)
	 && (scaledOffsetIndexIncr != 0);
	lastIndex = (startIndex + n) - 1;
	for (sliceIndex = startIndex; sliceIndex <= lastIndex; sliceIndex += 1) {
		sample = (scaledVol * (waveTable[(scaledIndex / ScaleFactor) + 1])) / ScaleFactor;
		if (doingFM) {
			offset = normalizedModulation * (waveTable[(scaledOffsetIndex / ScaleFactor) + 1]);
			scaledOffsetIndex = (scaledOffsetIndex + scaledOffsetIndexIncr) % scaledWaveTableSize;
			if (scaledOffsetIndex < 0) {
				scaledOffsetIndex += scaledWaveTableSize;
			}
			scaledIndex = ((scaledIndex + scaledIndexIncr) + offset) % scaledWaveTableSize;
			if (scaledIndex < 0) {
				scaledIndex += scaledWaveTableSize;
			}
		}
		else {
			scaledIndex = (scaledIndex + scaledIndexIncr) % scaledWaveTableSize;
		}
		if (leftVol > 0) {
			i = (2 * sliceIndex) - 1;
			s = (aSoundBuffer[i]) + ((sample * leftVol) / ScaleFactor);
			if (s > 0x7FFF) {
				s = 0x7FFF;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		if (rightVol > 0) {
			i = 2 * sliceIndex;
			s = (aSoundBuffer[i]) + ((sample * rightVol) / ScaleFactor);
			if (s > 0x7FFF) {
				s = 0x7FFF;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		if (scaledVolIncr != 0) {
			scaledVol += scaledVolIncr;
			if (((scaledVolIncr > 0)
			 && (scaledVol >= scaledVolLimit))
			 || ((scaledVolIncr < 0)
			 && (scaledVol <= scaledVolLimit))) {

				/* reached the limit; stop incrementing */


				/* reached the limit; stop incrementing */

				scaledVol = scaledVolLimit;
				scaledVolIncr = 0;
			}
		}
	}
	count -= n;
	if (!successFlag) {
		return null;
	}
	storeIntegerofObjectwithValue(3, rcvr, scaledVol);
	storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
	storeIntegerofObjectwithValue(7, rcvr, count);
	storeIntegerofObjectwithValue(10, rcvr, scaledIndex);
	storeIntegerofObjectwithValue(15, rcvr, scaledOffsetIndex);
	pop(5);
}


/*	Play samples from a wave table by stepping a fixed amount through the
	table on every sample. The table index and increment are scaled to allow
	fractional increments for greater pitch accuracy. If a loop length is
	specified, then the index is looped back when the loopEnd index is reached
	until count drops below releaseCount. This allows a short sampled sound to
	be sustained indefinitely.
 */
/*	(LoopedSampledSound pitch: 440.0 dur: 5.0 loudness: 0.5) play */

EXPORT(sqInt)
primitiveMixLoopedSampledSound(void)
{
	// LoopedSampledSound>>#primitiveMixLoopedSampledSound
    short int *aSoundBuffer;
    sqInt compositeLeftVol;
    sqInt compositeRightVol;
    sqInt count;
    sqInt i;
    sqInt isInStereo;
    sqInt lastIndex;
    sqInt lastSample;
    short int *leftSamples;
    sqInt leftVal;
    sqInt leftVol;
    sqInt loopEnd;
    sqInt m;
    sqInt n;
    sqInt nextSampleIndex;
    sqInt rcvr;
    sqInt releaseCount;
    short int *rightSamples;
    sqInt rightVal;
    sqInt rightVol;
    sqInt s;
    sqInt sampleIndex;
    sqInt scaledIndex;
    sqInt scaledIndexIncr;
    sqInt scaledLoopLength;
    sqInt scaledVol;
    sqInt scaledVolIncr;
    sqInt scaledVolLimit;
    sqInt sliceIndex;
    sqInt startIndex;

	rcvr = stackValue(5);
	n = stackIntegerValue(4);
	aSoundBuffer = arrayValueOf(stackValue(3));
	aSoundBuffer -= 1;
	startIndex = stackIntegerValue(2);
	leftVol = stackIntegerValue(1);
	rightVol = stackIntegerValue(0);
	scaledVol = fetchIntegerofObject(3, rcvr);
	scaledVolIncr = fetchIntegerofObject(4, rcvr);
	scaledVolLimit = fetchIntegerofObject(5, rcvr);
	count = fetchIntegerofObject(7, rcvr);
	releaseCount = fetchIntegerofObject(8, rcvr);
	leftSamples = fetchArrayofObject(10, rcvr);
	leftSamples -= 1;
	rightSamples = fetchArrayofObject(11, rcvr);
	rightSamples -= 1;
	lastSample = fetchIntegerofObject(16, rcvr);
	loopEnd = fetchIntegerofObject(17, rcvr);
	scaledLoopLength = fetchIntegerofObject(18, rcvr);
	scaledIndex = fetchIntegerofObject(19, rcvr);
	scaledIndexIncr = fetchIntegerofObject(20, rcvr);
	if (!successFlag) {
		return null;
	}
	isInStereo = leftSamples != rightSamples;
	compositeLeftVol = (leftVol * scaledVol) / ScaleFactor;
	compositeRightVol = (rightVol * scaledVol) / ScaleFactor;
	i = (2 * startIndex) - 1;
	lastIndex = (startIndex + n) - 1;
	for (sliceIndex = startIndex; sliceIndex <= lastIndex; sliceIndex += 1) {
		sampleIndex = ((scaledIndex += scaledIndexIncr)) / LoopIndexScaleFactor;
		if ((sampleIndex > loopEnd)
		 && (count > releaseCount)) {

			/* loop back if not within releaseCount of the note end */
			/* note: unlooped sounds will have loopEnd = lastSample */


			/* loop back if not within releaseCount of the note end */
			/* note: unlooped sounds will have loopEnd = lastSample */

			sampleIndex = ((scaledIndex -= scaledLoopLength)) / LoopIndexScaleFactor;
		}
		if (((nextSampleIndex = sampleIndex + 1)) > lastSample) {
			if (sampleIndex > lastSample) {
				count = 0;
				if (!successFlag) {
					return null;
				}
				storeIntegerofObjectwithValue(3, rcvr, scaledVol);
				storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
				storeIntegerofObjectwithValue(7, rcvr, count);
				storeIntegerofObjectwithValue(19, rcvr, scaledIndex);
				pop(6);
				pushInteger(null);
				return null;
			}
			if (scaledLoopLength == 0) {
				nextSampleIndex = sampleIndex;
			}
			else {
				nextSampleIndex = ((scaledIndex - scaledLoopLength) / LoopIndexScaleFactor) + 1;
			}
		}
		m = scaledIndex & LoopIndexFractionMask;
		rightVal = (leftVal = (((leftSamples[sampleIndex]) * (LoopIndexScaleFactor - m)) + ((leftSamples[nextSampleIndex]) * m)) / LoopIndexScaleFactor);
		if (isInStereo) {
			rightVal = (((rightSamples[sampleIndex]) * (LoopIndexScaleFactor - m)) + ((rightSamples[nextSampleIndex]) * m)) / LoopIndexScaleFactor;
		}
		if (leftVol > 0) {
			s = (aSoundBuffer[i]) + ((compositeLeftVol * leftVal) / ScaleFactor);
			if (s > 0x7FFF) {
				s = 0x7FFF;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		i += 1;
		if (rightVol > 0) {
			s = (aSoundBuffer[i]) + ((compositeRightVol * rightVal) / ScaleFactor);
			if (s > 0x7FFF) {
				s = 0x7FFF;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		i += 1;
		if (scaledVolIncr != 0) {

			/* update volume envelope if it is changing */


			/* update volume envelope if it is changing */

			scaledVol += scaledVolIncr;
			if (((scaledVolIncr > 0)
			 && (scaledVol >= scaledVolLimit))
			 || ((scaledVolIncr < 0)
			 && (scaledVol <= scaledVolLimit))) {

				/* reached the limit; stop incrementing */


				/* reached the limit; stop incrementing */

				scaledVol = scaledVolLimit;
				scaledVolIncr = 0;
			}
			compositeLeftVol = (leftVol * scaledVol) / ScaleFactor;
			compositeRightVol = (rightVol * scaledVol) / ScaleFactor;
		}
	}
	count -= n;
	if (!successFlag) {
		return null;
	}
	storeIntegerofObjectwithValue(3, rcvr, scaledVol);
	storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
	storeIntegerofObjectwithValue(7, rcvr, count);
	storeIntegerofObjectwithValue(19, rcvr, scaledIndex);
	pop(5);
}


/*	The Karplus-Strong plucked string algorithm: start with a buffer full of
	random noise and repeatedly play the contents of that buffer while
	averaging adjacent samples. High harmonics damp out more quickly,
	transfering their energy to lower ones. The length of the buffer
	corresponds to the length of the string.
 */
/*	(PluckedSound pitch: 220.0 dur: 6.0 loudness: 0.8) play */

EXPORT(sqInt)
primitiveMixPluckedSound(void)
{
	// PluckedSound>>#primitiveMixPluckedSound
    short int *aSoundBuffer;
    sqInt average;
    sqInt count;
    sqInt i;
    sqInt lastIndex;
    sqInt leftVol;
    sqInt n;
    sqInt rcvr;
    sqInt rightVol;
    short int *ring;
    sqInt s;
    sqInt sample;
    sqInt scaledIndex;
    sqInt scaledIndexIncr;
    sqInt scaledIndexLimit;
    sqInt scaledNextIndex;
    sqInt scaledThisIndex;
    sqInt scaledVol;
    sqInt scaledVolIncr;
    sqInt scaledVolLimit;
    sqInt sliceIndex;
    sqInt startIndex;

	rcvr = stackValue(5);
	n = stackIntegerValue(4);
	aSoundBuffer = arrayValueOf(stackValue(3));
	aSoundBuffer -= 1;
	startIndex = stackIntegerValue(2);
	leftVol = stackIntegerValue(1);
	rightVol = stackIntegerValue(0);
	scaledVol = fetchIntegerofObject(3, rcvr);
	scaledVolIncr = fetchIntegerofObject(4, rcvr);
	scaledVolLimit = fetchIntegerofObject(5, rcvr);
	count = fetchIntegerofObject(7, rcvr);
	ring = fetchArrayofObject(8, rcvr);
	ring -= 1;
	scaledIndex = fetchIntegerofObject(9, rcvr);
	scaledIndexIncr = fetchIntegerofObject(10, rcvr);
	scaledIndexLimit = fetchIntegerofObject(11, rcvr);
	if (!successFlag) {
		return null;
	}
	lastIndex = (startIndex + n) - 1;
	scaledThisIndex = (scaledNextIndex = scaledIndex);
	for (sliceIndex = startIndex; sliceIndex <= lastIndex; sliceIndex += 1) {
		scaledNextIndex = scaledThisIndex + scaledIndexIncr;
		if (scaledNextIndex >= scaledIndexLimit) {
			scaledNextIndex = ScaleFactor + (scaledNextIndex - scaledIndexLimit);
		}
		average = ((ring[scaledThisIndex / ScaleFactor]) + (ring[scaledNextIndex / ScaleFactor])) / 2;
		ring[scaledThisIndex / ScaleFactor] = average;

		/* scale by volume */

		sample = (average * scaledVol) / ScaleFactor;
		scaledThisIndex = scaledNextIndex;
		if (leftVol > 0) {
			i = (2 * sliceIndex) - 1;
			s = (aSoundBuffer[i]) + ((sample * leftVol) / ScaleFactor);
			if (s > 0x7FFF) {
				s = 0x7FFF;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		if (rightVol > 0) {
			i = 2 * sliceIndex;
			s = (aSoundBuffer[i]) + ((sample * rightVol) / ScaleFactor);
			if (s > 0x7FFF) {
				s = 0x7FFF;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		if (scaledVolIncr != 0) {
			scaledVol += scaledVolIncr;
			if (((scaledVolIncr > 0)
			 && (scaledVol >= scaledVolLimit))
			 || ((scaledVolIncr < 0)
			 && (scaledVol <= scaledVolLimit))) {

				/* reached the limit; stop incrementing */


				/* reached the limit; stop incrementing */

				scaledVol = scaledVolLimit;
				scaledVolIncr = 0;
			}
		}
	}
	scaledIndex = scaledNextIndex;
	count -= n;
	if (!successFlag) {
		return null;
	}
	storeIntegerofObjectwithValue(3, rcvr, scaledVol);
	storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
	storeIntegerofObjectwithValue(7, rcvr, count);
	storeIntegerofObjectwithValue(9, rcvr, scaledIndex);
	pop(5);
}


/*	Mix the given number of samples with the samples already in the given
	buffer starting at the given index. Assume that the buffer size is at
	least (index + count) - 1.
 */

EXPORT(sqInt)
primitiveMixSampledSound(void)
{
	// SampledSound>>#primitiveMixSampledSound
    short int *aSoundBuffer;
    sqInt count;
    sqInt i;
    sqInt indexHighBits;
    sqInt lastIndex;
    sqInt leftVol;
    sqInt n;
    sqInt outIndex;
    sqInt overflow;
    sqInt rcvr;
    sqInt rightVol;
    sqInt s;
    sqInt sample;
    sqInt sampleIndex;
    short int *samples;
    sqInt samplesSize;
    sqInt scaledIncrement;
    sqInt scaledIndex;
    sqInt scaledVol;
    sqInt scaledVolIncr;
    sqInt scaledVolLimit;
    sqInt startIndex;

	rcvr = stackValue(5);
	n = stackIntegerValue(4);
	aSoundBuffer = arrayValueOf(stackValue(3));
	aSoundBuffer -= 1;
	startIndex = stackIntegerValue(2);
	leftVol = stackIntegerValue(1);
	rightVol = stackIntegerValue(0);
	scaledVol = fetchIntegerofObject(3, rcvr);
	scaledVolIncr = fetchIntegerofObject(4, rcvr);
	scaledVolLimit = fetchIntegerofObject(5, rcvr);
	count = fetchIntegerofObject(7, rcvr);
	samples = fetchArrayofObject(8, rcvr);
	samples -= 1;
	samplesSize = fetchIntegerofObject(10, rcvr);
	scaledIndex = fetchIntegerofObject(11, rcvr);
	indexHighBits = fetchIntegerofObject(12, rcvr);
	scaledIncrement = fetchIntegerofObject(13, rcvr);
	if (!successFlag) {
		return null;
	}
	lastIndex = (startIndex + n) - 1;

	/* index of next stereo output sample pair */

	outIndex = startIndex;
	sampleIndex = indexHighBits + (((usqInt) scaledIndex) >> IncrementFractionBits);
	while ((sampleIndex <= samplesSize)
	 && (outIndex <= lastIndex)) {
		sample = ((samples[sampleIndex]) * scaledVol) / ScaleFactor;
		if (leftVol > 0) {
			i = (2 * outIndex) - 1;
			s = (aSoundBuffer[i]) + ((sample * leftVol) / ScaleFactor);
			if (s > 0x7FFF) {
				s = 0x7FFF;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		if (rightVol > 0) {
			i = 2 * outIndex;
			s = (aSoundBuffer[i]) + ((sample * rightVol) / ScaleFactor);
			if (s > 0x7FFF) {
				s = 0x7FFF;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		if (scaledVolIncr != 0) {
			scaledVol += scaledVolIncr;
			if (((scaledVolIncr > 0)
			 && (scaledVol >= scaledVolLimit))
			 || ((scaledVolIncr < 0)
			 && (scaledVol <= scaledVolLimit))) {

				/* reached the limit; stop incrementing */


				/* reached the limit; stop incrementing */

				scaledVol = scaledVolLimit;
				scaledVolIncr = 0;
			}
		}
		scaledIndex += scaledIncrement;
		if (scaledIndex >= ScaledIndexOverflow) {
			overflow = ((usqInt) scaledIndex) >> IncrementFractionBits;
			indexHighBits += overflow;
			scaledIndex -= overflow << IncrementFractionBits;
		}
		sampleIndex = indexHighBits + (((usqInt) scaledIndex) >> IncrementFractionBits);
		outIndex += 1;
	}
	count -= n;
	if (!successFlag) {
		return null;
	}
	storeIntegerofObjectwithValue(3, rcvr, scaledVol);
	storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
	storeIntegerofObjectwithValue(7, rcvr, count);
	storeIntegerofObjectwithValue(11, rcvr, scaledIndex);
	storeIntegerofObjectwithValue(12, rcvr, indexHighBits);
	pop(5);
}


/*	Note: This is coded so that it can be run in Squeak. */

EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	// InterpreterPlugin>>#setInterpreter:
    sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* SoundGenerationPlugin_exports[][3] = {
	{"SoundGenerationPlugin", "getModuleName", (void*)getModuleName},
	{"SoundGenerationPlugin", "primitiveApplyReverb\000\001", (void*)primitiveApplyReverb},
	{"SoundGenerationPlugin", "primitiveMixFMSound\000\001", (void*)primitiveMixFMSound},
	{"SoundGenerationPlugin", "primitiveMixLoopedSampledSound\000\001", (void*)primitiveMixLoopedSampledSound},
	{"SoundGenerationPlugin", "primitiveMixPluckedSound\000\001", (void*)primitiveMixPluckedSound},
	{"SoundGenerationPlugin", "primitiveMixSampledSound\000\001", (void*)primitiveMixSampledSound},
	{"SoundGenerationPlugin", "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveApplyReverbAccessorDepth = 1;
signed char primitiveMixFMSoundAccessorDepth = 1;
signed char primitiveMixLoopedSampledSoundAccessorDepth = 1;
signed char primitiveMixPluckedSoundAccessorDepth = 1;
signed char primitiveMixSampledSoundAccessorDepth = 1;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
