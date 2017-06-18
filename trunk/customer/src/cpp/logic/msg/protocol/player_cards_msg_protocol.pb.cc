// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: player_cards_msg_protocol.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "player_cards_msg_protocol.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace gamer {
namespace protocol {

namespace {

const ::google::protobuf::Descriptor* PlayerCardsMsgProtocol_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PlayerCardsMsgProtocol_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_player_5fcards_5fmsg_5fprotocol_2eproto() {
  protobuf_AddDesc_player_5fcards_5fmsg_5fprotocol_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "player_cards_msg_protocol.proto");
  GOOGLE_CHECK(file != NULL);
  PlayerCardsMsgProtocol_descriptor_ = file->message_type(0);
  static const int PlayerCardsMsgProtocol_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerCardsMsgProtocol, player_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerCardsMsgProtocol, visible_hand_cards_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerCardsMsgProtocol, invisible_hand_cards_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerCardsMsgProtocol, flower_cards_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerCardsMsgProtocol, season_cards_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerCardsMsgProtocol, waiting_cards_),
  };
  PlayerCardsMsgProtocol_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PlayerCardsMsgProtocol_descriptor_,
      PlayerCardsMsgProtocol::default_instance_,
      PlayerCardsMsgProtocol_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerCardsMsgProtocol, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerCardsMsgProtocol, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(PlayerCardsMsgProtocol));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_player_5fcards_5fmsg_5fprotocol_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PlayerCardsMsgProtocol_descriptor_, &PlayerCardsMsgProtocol::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_player_5fcards_5fmsg_5fprotocol_2eproto() {
  delete PlayerCardsMsgProtocol::default_instance_;
  delete PlayerCardsMsgProtocol_reflection_;
}

void protobuf_AddDesc_player_5fcards_5fmsg_5fprotocol_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\037player_cards_msg_protocol.proto\022\016gamer"
    ".protocol\"\253\001\n\026PlayerCardsMsgProtocol\022\024\n\t"
    "player_id\030\001 \001(\005:\0010\022\032\n\022visible_hand_cards"
    "\030\002 \003(\005\022\034\n\024invisible_hand_cards\030\003 \003(\005\022\024\n\014"
    "flower_cards\030\004 \003(\005\022\024\n\014season_cards\030\005 \003(\005"
    "\022\025\n\rwaiting_cards\030\006 \003(\005", 223);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "player_cards_msg_protocol.proto", &protobuf_RegisterTypes);
  PlayerCardsMsgProtocol::default_instance_ = new PlayerCardsMsgProtocol();
  PlayerCardsMsgProtocol::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_player_5fcards_5fmsg_5fprotocol_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_player_5fcards_5fmsg_5fprotocol_2eproto {
  StaticDescriptorInitializer_player_5fcards_5fmsg_5fprotocol_2eproto() {
    protobuf_AddDesc_player_5fcards_5fmsg_5fprotocol_2eproto();
  }
} static_descriptor_initializer_player_5fcards_5fmsg_5fprotocol_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int PlayerCardsMsgProtocol::kPlayerIdFieldNumber;
const int PlayerCardsMsgProtocol::kVisibleHandCardsFieldNumber;
const int PlayerCardsMsgProtocol::kInvisibleHandCardsFieldNumber;
const int PlayerCardsMsgProtocol::kFlowerCardsFieldNumber;
const int PlayerCardsMsgProtocol::kSeasonCardsFieldNumber;
const int PlayerCardsMsgProtocol::kWaitingCardsFieldNumber;
#endif  // !_MSC_VER

PlayerCardsMsgProtocol::PlayerCardsMsgProtocol()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gamer.protocol.PlayerCardsMsgProtocol)
}

void PlayerCardsMsgProtocol::InitAsDefaultInstance() {
}

PlayerCardsMsgProtocol::PlayerCardsMsgProtocol(const PlayerCardsMsgProtocol& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gamer.protocol.PlayerCardsMsgProtocol)
}

void PlayerCardsMsgProtocol::SharedCtor() {
  _cached_size_ = 0;
  player_id_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PlayerCardsMsgProtocol::~PlayerCardsMsgProtocol() {
  // @@protoc_insertion_point(destructor:gamer.protocol.PlayerCardsMsgProtocol)
  SharedDtor();
}

void PlayerCardsMsgProtocol::SharedDtor() {
  if (this != default_instance_) {
  }
}

void PlayerCardsMsgProtocol::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PlayerCardsMsgProtocol::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PlayerCardsMsgProtocol_descriptor_;
}

const PlayerCardsMsgProtocol& PlayerCardsMsgProtocol::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_player_5fcards_5fmsg_5fprotocol_2eproto();
  return *default_instance_;
}

PlayerCardsMsgProtocol* PlayerCardsMsgProtocol::default_instance_ = NULL;

PlayerCardsMsgProtocol* PlayerCardsMsgProtocol::New() const {
  return new PlayerCardsMsgProtocol;
}

void PlayerCardsMsgProtocol::Clear() {
  player_id_ = 0;
  visible_hand_cards_.Clear();
  invisible_hand_cards_.Clear();
  flower_cards_.Clear();
  season_cards_.Clear();
  waiting_cards_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool PlayerCardsMsgProtocol::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gamer.protocol.PlayerCardsMsgProtocol)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 player_id = 1 [default = 0];
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &player_id_)));
          set_has_player_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_visible_hand_cards;
        break;
      }

      // repeated int32 visible_hand_cards = 2;
      case 2: {
        if (tag == 16) {
         parse_visible_hand_cards:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 16, input, this->mutable_visible_hand_cards())));
        } else if (tag == 18) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_visible_hand_cards())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_visible_hand_cards;
        if (input->ExpectTag(24)) goto parse_invisible_hand_cards;
        break;
      }

      // repeated int32 invisible_hand_cards = 3;
      case 3: {
        if (tag == 24) {
         parse_invisible_hand_cards:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 24, input, this->mutable_invisible_hand_cards())));
        } else if (tag == 26) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_invisible_hand_cards())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_invisible_hand_cards;
        if (input->ExpectTag(32)) goto parse_flower_cards;
        break;
      }

      // repeated int32 flower_cards = 4;
      case 4: {
        if (tag == 32) {
         parse_flower_cards:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 32, input, this->mutable_flower_cards())));
        } else if (tag == 34) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_flower_cards())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_flower_cards;
        if (input->ExpectTag(40)) goto parse_season_cards;
        break;
      }

      // repeated int32 season_cards = 5;
      case 5: {
        if (tag == 40) {
         parse_season_cards:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 40, input, this->mutable_season_cards())));
        } else if (tag == 42) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_season_cards())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_season_cards;
        if (input->ExpectTag(48)) goto parse_waiting_cards;
        break;
      }

      // repeated int32 waiting_cards = 6;
      case 6: {
        if (tag == 48) {
         parse_waiting_cards:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 48, input, this->mutable_waiting_cards())));
        } else if (tag == 50) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_waiting_cards())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_waiting_cards;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:gamer.protocol.PlayerCardsMsgProtocol)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gamer.protocol.PlayerCardsMsgProtocol)
  return false;
#undef DO_
}

void PlayerCardsMsgProtocol::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gamer.protocol.PlayerCardsMsgProtocol)
  // optional int32 player_id = 1 [default = 0];
  if (has_player_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->player_id(), output);
  }

  // repeated int32 visible_hand_cards = 2;
  for (int i = 0; i < this->visible_hand_cards_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      2, this->visible_hand_cards(i), output);
  }

  // repeated int32 invisible_hand_cards = 3;
  for (int i = 0; i < this->invisible_hand_cards_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      3, this->invisible_hand_cards(i), output);
  }

  // repeated int32 flower_cards = 4;
  for (int i = 0; i < this->flower_cards_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      4, this->flower_cards(i), output);
  }

  // repeated int32 season_cards = 5;
  for (int i = 0; i < this->season_cards_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      5, this->season_cards(i), output);
  }

  // repeated int32 waiting_cards = 6;
  for (int i = 0; i < this->waiting_cards_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      6, this->waiting_cards(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gamer.protocol.PlayerCardsMsgProtocol)
}

::google::protobuf::uint8* PlayerCardsMsgProtocol::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gamer.protocol.PlayerCardsMsgProtocol)
  // optional int32 player_id = 1 [default = 0];
  if (has_player_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->player_id(), target);
  }

  // repeated int32 visible_hand_cards = 2;
  for (int i = 0; i < this->visible_hand_cards_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(2, this->visible_hand_cards(i), target);
  }

  // repeated int32 invisible_hand_cards = 3;
  for (int i = 0; i < this->invisible_hand_cards_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(3, this->invisible_hand_cards(i), target);
  }

  // repeated int32 flower_cards = 4;
  for (int i = 0; i < this->flower_cards_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(4, this->flower_cards(i), target);
  }

  // repeated int32 season_cards = 5;
  for (int i = 0; i < this->season_cards_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(5, this->season_cards(i), target);
  }

  // repeated int32 waiting_cards = 6;
  for (int i = 0; i < this->waiting_cards_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(6, this->waiting_cards(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gamer.protocol.PlayerCardsMsgProtocol)
  return target;
}

int PlayerCardsMsgProtocol::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 player_id = 1 [default = 0];
    if (has_player_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->player_id());
    }

  }
  // repeated int32 visible_hand_cards = 2;
  {
    int data_size = 0;
    for (int i = 0; i < this->visible_hand_cards_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->visible_hand_cards(i));
    }
    total_size += 1 * this->visible_hand_cards_size() + data_size;
  }

  // repeated int32 invisible_hand_cards = 3;
  {
    int data_size = 0;
    for (int i = 0; i < this->invisible_hand_cards_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->invisible_hand_cards(i));
    }
    total_size += 1 * this->invisible_hand_cards_size() + data_size;
  }

  // repeated int32 flower_cards = 4;
  {
    int data_size = 0;
    for (int i = 0; i < this->flower_cards_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->flower_cards(i));
    }
    total_size += 1 * this->flower_cards_size() + data_size;
  }

  // repeated int32 season_cards = 5;
  {
    int data_size = 0;
    for (int i = 0; i < this->season_cards_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->season_cards(i));
    }
    total_size += 1 * this->season_cards_size() + data_size;
  }

  // repeated int32 waiting_cards = 6;
  {
    int data_size = 0;
    for (int i = 0; i < this->waiting_cards_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->waiting_cards(i));
    }
    total_size += 1 * this->waiting_cards_size() + data_size;
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PlayerCardsMsgProtocol::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const PlayerCardsMsgProtocol* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PlayerCardsMsgProtocol*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PlayerCardsMsgProtocol::MergeFrom(const PlayerCardsMsgProtocol& from) {
  GOOGLE_CHECK_NE(&from, this);
  visible_hand_cards_.MergeFrom(from.visible_hand_cards_);
  invisible_hand_cards_.MergeFrom(from.invisible_hand_cards_);
  flower_cards_.MergeFrom(from.flower_cards_);
  season_cards_.MergeFrom(from.season_cards_);
  waiting_cards_.MergeFrom(from.waiting_cards_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_player_id()) {
      set_player_id(from.player_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void PlayerCardsMsgProtocol::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PlayerCardsMsgProtocol::CopyFrom(const PlayerCardsMsgProtocol& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PlayerCardsMsgProtocol::IsInitialized() const {

  return true;
}

void PlayerCardsMsgProtocol::Swap(PlayerCardsMsgProtocol* other) {
  if (other != this) {
    std::swap(player_id_, other->player_id_);
    visible_hand_cards_.Swap(&other->visible_hand_cards_);
    invisible_hand_cards_.Swap(&other->invisible_hand_cards_);
    flower_cards_.Swap(&other->flower_cards_);
    season_cards_.Swap(&other->season_cards_);
    waiting_cards_.Swap(&other->waiting_cards_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata PlayerCardsMsgProtocol::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PlayerCardsMsgProtocol_descriptor_;
  metadata.reflection = PlayerCardsMsgProtocol_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace gamer

// @@protoc_insertion_point(global_scope)
