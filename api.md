# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`DynamicSortTest`](#classDynamicSortTest) | The class that will handle testing the sort function manually.
`class `[`DynamicTest`](#classDynamicTest) | 
`class `[`LinkedList`](#classLinkedList) | 
`class `[`MergeSortTest`](#classMergeSortTest) | 
`class `[`Node`](#classNode) | 

# class `DynamicSortTest` 

```
class DynamicSortTest
  : public DynamicTest
```  

The class that will handle testing the sort function manually.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`DynamicSortTest`](#classDynamicSortTest_1a34c13534f2a17cb2544011ad3cb7d632)`()` | 
`public virtual void `[`testOperation`](#classDynamicSortTest_1a690020be54f0f191e962683acc3b2dc3)`()` | The function that will test merge sort.

## Members

#### `public  `[`DynamicSortTest`](#classDynamicSortTest_1a34c13534f2a17cb2544011ad3cb7d632)`()` 

#### `public virtual void `[`testOperation`](#classDynamicSortTest_1a690020be54f0f191e962683acc3b2dc3)`()` 

The function that will test merge sort.

# class `DynamicTest` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`DynamicTest`](#classDynamicTest_1ac36203fc3c36c096019083e4abecc355)`(string name)` | 
`public string `[`prompt`](#classDynamicTest_1ab0a5243fe8b4ec2cbebc310fa9f106bd)`(string question)` | 
`public void `[`promptUserToInsertDataItem`](#classDynamicTest_1a7389d6d679fb96880d90cf89c03fe453)`(bool & shouldContinue)` | 
`public void `[`promptUserToInsertData`](#classDynamicTest_1adafa24e06ec42e2da303243fb081687d)`()` | 
`public void `[`testOperation`](#classDynamicTest_1a088ade32f394d95fd1dc6ed1ee21adea)`()` | 
`public `[`Node`](#classNode)`< string > * `[`promptUserToFindItem`](#classDynamicTest_1a855be3e75b5a2e1f6c92275c3ff36b35)`()` | 
`public void `[`showWhetherItemWasFound`](#classDynamicTest_1a8a6e49fc4604ce5e85307f88c29b0d48)`(`[`Node`](#classNode)`< string > * item)` | 
`public void `[`startTest`](#classDynamicTest_1a13fc08981c590a35dd1277ddc1f02e26)`()` | 
`protected `[`LinkedList`](#classLinkedList)`< string > `[`linkedList`](#classDynamicTest_1aa786a63507db421d2918bdbdf03debe7) | 

## Members

#### `public  `[`DynamicTest`](#classDynamicTest_1ac36203fc3c36c096019083e4abecc355)`(string name)` 

#### `public string `[`prompt`](#classDynamicTest_1ab0a5243fe8b4ec2cbebc310fa9f106bd)`(string question)` 

#### `public void `[`promptUserToInsertDataItem`](#classDynamicTest_1a7389d6d679fb96880d90cf89c03fe453)`(bool & shouldContinue)` 

#### `public void `[`promptUserToInsertData`](#classDynamicTest_1adafa24e06ec42e2da303243fb081687d)`()` 

#### `public void `[`testOperation`](#classDynamicTest_1a088ade32f394d95fd1dc6ed1ee21adea)`()` 

#### `public `[`Node`](#classNode)`< string > * `[`promptUserToFindItem`](#classDynamicTest_1a855be3e75b5a2e1f6c92275c3ff36b35)`()` 

#### `public void `[`showWhetherItemWasFound`](#classDynamicTest_1a8a6e49fc4604ce5e85307f88c29b0d48)`(`[`Node`](#classNode)`< string > * item)` 

#### `public void `[`startTest`](#classDynamicTest_1a13fc08981c590a35dd1277ddc1f02e26)`()` 

#### `protected `[`LinkedList`](#classLinkedList)`< string > `[`linkedList`](#classDynamicTest_1aa786a63507db421d2918bdbdf03debe7) 

# class `LinkedList` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`Node`](#classNode)`< Data > * `[`head`](#classLinkedList_1af1c7cfb136396e24aa7f574eaf02bbf1) | 
`public `[`Node`](#classNode)`< Data > * `[`tail`](#classLinkedList_1a9b70005fff424dc8cb32f4e8ec7c4dee) | 
`public  `[`LinkedList`](#classLinkedList_1a3e6d3520c705dbebb35d4e74f63be9bd)`(Data defaultValue)` | 
`public `[`Node`](#classNode)`< Data > * `[`getHead`](#classLinkedList_1aaadcea916853080de32415778314d79b)`()` | 
`public void `[`setHead`](#classLinkedList_1a30a609d015bf7f97d28b3e79130a7072)`(`[`Node`](#classNode)`< Data > * newHead)` | 
`public `[`Node`](#classNode)`< Data > * `[`getTail`](#classLinkedList_1a8b019abfb9ebf50eedfb62d34ecc21ee)`()` | 
`public `[`Node`](#classNode)`< Data > * `[`Find`](#classLinkedList_1a4e9bcc9e8b16ff98794e4f135825a0c6)`(Data * data)` | 
`public void `[`Insert`](#classLinkedList_1a81a20f0d3a77cf841ec6270b62237f78)`(Data data)` | 
`public void `[`Delete`](#classLinkedList_1a1eea967f53263e217f5447215e5b6a2d)`(`[`Node`](#classNode)`< Data > * node)` | 

## Members

#### `public `[`Node`](#classNode)`< Data > * `[`head`](#classLinkedList_1af1c7cfb136396e24aa7f574eaf02bbf1) 

#### `public `[`Node`](#classNode)`< Data > * `[`tail`](#classLinkedList_1a9b70005fff424dc8cb32f4e8ec7c4dee) 

#### `public  `[`LinkedList`](#classLinkedList_1a3e6d3520c705dbebb35d4e74f63be9bd)`(Data defaultValue)` 

#### `public `[`Node`](#classNode)`< Data > * `[`getHead`](#classLinkedList_1aaadcea916853080de32415778314d79b)`()` 

#### `public void `[`setHead`](#classLinkedList_1a30a609d015bf7f97d28b3e79130a7072)`(`[`Node`](#classNode)`< Data > * newHead)` 

#### `public `[`Node`](#classNode)`< Data > * `[`getTail`](#classLinkedList_1a8b019abfb9ebf50eedfb62d34ecc21ee)`()` 

#### `public `[`Node`](#classNode)`< Data > * `[`Find`](#classLinkedList_1a4e9bcc9e8b16ff98794e4f135825a0c6)`(Data * data)` 

#### `public void `[`Insert`](#classLinkedList_1a81a20f0d3a77cf841ec6270b62237f78)`(Data data)` 

#### `public void `[`Delete`](#classLinkedList_1a1eea967f53263e217f5447215e5b6a2d)`(`[`Node`](#classNode)`< Data > * node)` 

# class `MergeSortTest` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`MergeSortTest`](#classMergeSortTest_1a1fca46a00b1de90a305aa03b7ece7c8c)`(vector< int > nodeData)` | 
`public inline  `[`~MergeSortTest`](#classMergeSortTest_1a75d5bfccfe2ff87def03ff679a398e45)`()` | 
`public inline void `[`runTests`](#classMergeSortTest_1aedce0925e73316c782ad18af5266ae42)`()` | 

## Members

#### `public inline  `[`MergeSortTest`](#classMergeSortTest_1a1fca46a00b1de90a305aa03b7ece7c8c)`(vector< int > nodeData)` 

#### `public inline  `[`~MergeSortTest`](#classMergeSortTest_1a75d5bfccfe2ff87def03ff679a398e45)`()` 

#### `public inline void `[`runTests`](#classMergeSortTest_1aedce0925e73316c782ad18af5266ae42)`()` 

# class `Node` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`Node`](#classNode)` * `[`previous`](#classNode_1a8699f0fa6a8e4887ebb2bcd2f8854002) | 
`public `[`Node`](#classNode)` * `[`next`](#classNode_1aadec4f1223d56f3b220a176191d2eb61) | 
`public  `[`Node`](#classNode_1a6bdb52377ad45116501e66bc7b5178ed)`(Data data)` | 
`public Data * `[`getData`](#classNode_1ab3da8cf673a8ce4615b2219bfa35a746)`()` | 
`public void `[`setData`](#classNode_1a8e3a2e56d73ccb7322e8501335160a78)`(Data data)` | 
`public `[`Node`](#classNode)` * `[`getPrevious`](#classNode_1af458e0e1ad2155dd8a0b69200ee7e219)`()` | 
`public void `[`setPrevious`](#classNode_1a1530d8a023d43ed56da7317e3da3c177)`(`[`Node`](#classNode)` * previous)` | 
`public `[`Node`](#classNode)` * `[`getNext`](#classNode_1a0c9105da21759d0d0a2f0929c27e0f64)`()` | 
`public void `[`setNext`](#classNode_1a48984e88cec233089de303bdfac338b4)`(`[`Node`](#classNode)` * next)` | 

## Members

#### `public `[`Node`](#classNode)` * `[`previous`](#classNode_1a8699f0fa6a8e4887ebb2bcd2f8854002) 

#### `public `[`Node`](#classNode)` * `[`next`](#classNode_1aadec4f1223d56f3b220a176191d2eb61) 

#### `public  `[`Node`](#classNode_1a6bdb52377ad45116501e66bc7b5178ed)`(Data data)` 

#### `public Data * `[`getData`](#classNode_1ab3da8cf673a8ce4615b2219bfa35a746)`()` 

#### `public void `[`setData`](#classNode_1a8e3a2e56d73ccb7322e8501335160a78)`(Data data)` 

#### `public `[`Node`](#classNode)` * `[`getPrevious`](#classNode_1af458e0e1ad2155dd8a0b69200ee7e219)`()` 

#### `public void `[`setPrevious`](#classNode_1a1530d8a023d43ed56da7317e3da3c177)`(`[`Node`](#classNode)` * previous)` 

#### `public `[`Node`](#classNode)` * `[`getNext`](#classNode_1a0c9105da21759d0d0a2f0929c27e0f64)`()` 

#### `public void `[`setNext`](#classNode_1a48984e88cec233089de303bdfac338b4)`(`[`Node`](#classNode)` * next)` 

Generated by [Moxygen](https://sourcey.com/moxygen)